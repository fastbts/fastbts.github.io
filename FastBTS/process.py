import matplotlib.pyplot as plt
import numpy as np
import os


###############################for our test#####################################
data = []
name = "b.txt"
print(name)
#name = "b.txt"
with open(name) as f:
    data = f.readlines()
    f.close()

speed = []
time = []
tmp_speed = []
tmp_time = []
s_group_index = 0

if_continue = 0;
max_start_up = 0

start_us = 0
start_usg = 0
start_s = 0
start_sg = 0

good_start_s = 0
good_start_us = 0
start_lock = 0
threads_num2 = 1


for i in range(len(data)):
    if if_continue == 1:
        break;
    if data[i].split("\t")[0] != "80":
        continue;
    if start_lock == 0:
        start_lock = 1
        tart_us = data[i].split("\t")[4]
        start_usg = float(start_us)
        start_s = data[i].split("\t")[3]
        start_sg = float(start_s)

    if int(data[i].split("\t")[1]) == 0:
        m_tmp_data = data[i].split("\t")[2]
        if float(m_tmp_data.strip("\n")) > max_start_up:
            max_start_up = float(m_tmp_data.strip("\n"))
            m_tmp_time_s = data[i].split("\t")[3]
            m_tmp_time_us = data[i].split("\t")[4]
            good_start_s = float(m_tmp_time_s.strip("\n"))
            good_start_us = float(m_tmp_time_us.strip("\n"))
print(max_start_up)
for i in range(len(data)):
    m_tmp_data = data[i].split("\t")[2]
    if float(m_tmp_data.strip("\n")) > max_start_up:
        print(i, float(m_tmp_data.strip("\n")), max_start_up)
print('################')

final_start_speed = max_start_up/1024/1024/16*1000*1000*1600/1024/1024
final_start_time = good_start_s - start_sg + (good_start_us - start_usg)/1000000
print("Start_up_speed: ", str(final_start_speed), "Mbps  Start_up_time: ", str(final_start_time) + 's')


my_start_i = 0
my_start_lock = 0
data = data[2000:]

for i in range(len(data)):
    strdata = int(data[i].split("\t")[0])
    #print(strdata)
    if strdata != 80:
        #print("!!!")
        continue
    #print(s_group_index)
    if i != len(data)-1:
        if my_start_lock == 0:
            my_start_lock = 1
            my_start_i = i
        m_tmp_data = data[i].split("\t")[2]
        m_tmp_time_s = data[i].split("\t")[3]
        m_tmp_time_us = data[i].split("\t")[4]
        tmp_speed.append(float(m_tmp_data.strip("\n")))
        #print(len(tmp_speed))
        tmp_time.append([float(m_tmp_time_s.strip("\n")),float(m_tmp_time_us.strip("\n"))])
        s_group_index = s_group_index + 1
    else:
        print(s_group_index)
        if s_group_index >= 100:
            speed = tmp_speed
            time = tmp_time
            break;
        else:
            print(i)
            if i == len(data)-1:
                speed = tmp_speed
                print(len(speed))
                time = tmp_time
                break;
            my_start_lock = 0
            s_group_index = 0
            tmp_speed = []
            tmp_time = []
#print(time)
if len(speed) == 0:
    speed = tmp_speed
    time = tmp_time

speed = np.array(speed)
time = np.array(time)


filter_speed = []
filter_time = []
thr = np.mean(speed)
for i in range(len(speed)):
    filter_speed.append(speed[i]+0.00000000000001-0.00000000000001)
    filter_time.append(time[i])

filter_speed = np.array(filter_speed)
filter_time = np.array(filter_time)
filter_time_good = []
for i in range(len(filter_time)):
    filter_time_good.append(float(filter_time[i][0] + filter_time[i][1]/1000000))
filter_time_good = np.array(filter_time_good)

# ###############################for baseline#####################################
threads_num = 1

count = 0
group_index = 0
baseline_speed = []
baseline_time = []
for i in range(len(data)):
    if data[i].split("\t")[0] != "80":
        continue
    tmp_data = data[i].split("\t")[2]
    tmp_time_s = data[i].split("\t")[3]
    tmp_time_us = data[i].split("\t")[4]
    if int(data[i].split("\t")[1]) == 2:
        baseline_speed.append(float(tmp_data.strip("\n")))
        baseline_time.append([float(tmp_time_s.strip("\n")),float(tmp_time_us.strip("\n"))])
        group_index = group_index + 1
    else:
        if group_index >= 100:
            break
        else:
            group_index = 0
            count = count + 1

baseline_speed = np.array(baseline_speed)
baseline_time = np.array(baseline_time)

overall_time = -((baseline_time[0][0] - baseline_time[len(baseline_time)-1][0])+(baseline_time[0][1] - baseline_time[len(baseline_time)-1][1])/1000000)

#For baseline throughput
baseline_throughput = 0
for i in range(len(baseline_speed)-1):
    tmp_speed1 = baseline_speed[i]/1024/1024/16*1000*1000*1500/1024/1024
    tmp_speed2 = baseline_speed[i+1]/1024/1024/16*1000*1000*1500/1024/1024
    tmp_time = baseline_time[i+1][0] - baseline_time[i][0] +(baseline_time[i+1][1] - baseline_time[i][1])/1000000
    baseline_throughput = baseline_throughput + (tmp_speed1 + tmp_speed2)*tmp_time/2

print("Baseline Time:", str(overall_time),"s    Baseline Speed:",np.mean(baseline_speed)/1024/1024/16*1000*1000*1500/1024/1024*8*threads_num, "Mbps       Baseline throughtput:", str(baseline_throughput*threads_num), "MB")


# ###############another data#####################
# # filter_speed.astype(np.float32)
# # for i in range(len(filter_speed)):
# #   #filter_speed[i] = float(filter_speed[i])+0.1
# #   filter_speed[i] = float(filter_speed[i])/1024/1024/16*1500*1000*1000/1024/1024*8
# #   print(filter_speed[i])


# #################draw plot#######################
# # x_axis = np.linspace(1, len(filter_speed), len(filter_speed), endpoint=True)
# # y_axis = np.array(filter_speed)
# # plt.plot(x_axis, y_axis)
# # plt.show()


# ##################for crucial interval################
#print(filter_time_good)
init_length = 100 #init length
now_index = init_length
time_interval = 0.05
# turn_speed = filter_speed[0:init_length]

final_i = 0
final_j = 0

mean_1 = 0;
mean_2 = 0;
mean_3 = 0;

while 1:
    #calculate speed
    min_interval = 1
    max_data = 0
    max_i = 0
    max_j = 0
    tmp_data = filter_speed[0:now_index]
    tmp_data = np.array(tmp_data)
    np.sort(tmp_data)
    for i in range(len(filter_speed[0:now_index])-1):
        tmp_len = len(filter_speed[0:now_index])-1
        j = i+1
        while j <= tmp_len:
            if tmp_data[j] - tmp_data[i] >= min_interval:
                tmp_max = (j-i+1)*(j-i+1)/(tmp_data[j] - tmp_data[i])
                if tmp_max > max_data:
                    max_data = tmp_max
                    max_i = i;
                    max_j = j;
            j = j+1;
    mean_1 = mean_2
    mean_2 = mean_3
    mean_3 = np.mean(tmp_data[max_i:max_j])
    #print(mean_1, mean_2, mean_3)
    if mean_2 > 0.9*mean_1 and mean_2 < 1.1*mean_1 and mean_3 > 0.9*mean_2 and mean_3 < 1.1*mean_2:
        final_i = max_i
        final_j = max_j
        break

    #update now_index
    new_now = now_index+1
    while 1:
        if filter_time_good[new_now] - filter_time_good[now_index] > 0.05:
            break
        new_now = new_now + 1
    #print(new_now)
    now_index = new_now

print(now_index)

optimized_throughput = 0
for i in range(now_index+my_start_i):
    tmp_sp1 = speed[i]/1024/1024/16*1000*1000*1600/1024/1024
    tmp_sp2 = speed[i+1]/1024/1024/16*1000*1000*1600/1024/1024
    tmp_time = time[i+1][0] - time[i][0] + (time[i+1][1] - time[i][1])/1000000
    optimized_throughput = optimized_throughput + (tmp_sp1 + tmp_sp2)*tmp_time/2

print("Optimized Time:", str(time[final_j+my_start_i][0]-time[0][0] + (time[final_j+my_start_i][1] - time[0][1])/1000000),"s    Optimized Speed:",np.mean(filter_speed[final_i:final_j])/1024/1024/16*1000*1000*1600/1024/1024*8*threads_num, "Mbps       Optimized throughtput:", str(optimized_throughput), "MB")
# #print(final_i, final_j, np.mean(filter_speed[final_i:final_j])/1024/1024/16*1000*1000*1500/1024/1024*8*threads_num)




# # min_interval = 1
# # max_data = 0
# # max_i = 0
# # max_j = 0


# # print(max_j,np.mean(filter_speed[max_i:max_j])/1024/1024/16*1000*1000*1500/1024/1024*8*threads_num)
