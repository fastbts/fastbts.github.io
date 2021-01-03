
## Installation of the tcp_fastbts module

Recommended Environment: Ubuntu 16+  with kernel v5.0.1

Kernel Installation:

```shell
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-headers-5.0.1-050001_5.0.1-050001.201903100732_all.deb
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-headers-5.0.1-050001-generic_5.0.1-050001.201903100732_amd64.deb
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-image-unsigned-5.0.1-050001-generic_5.0.1-050001.201903100732_amd64.deb
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-modules-5.0.1-050001-generic_5.0.1-050001.201903100732_amd64.deb
sudo dpkg -i ***.deb

```

Remove other kernels (or change the boot priority):
```shell
dpkg --get-selections| grep linux
sudo apt-get remove [your old kernels]
```

Compile and install tcp_fastbts
```shell
make
make install
```

Switch the congestion control algorithm to tcp_fastbts
```shell
echo "" >/etc/sysctl.conf
echo "net.core.default_qdisc=fq" >> /etc/sysctl.conf
echo "net.ipv4.tcp_congestion_control=fastbts" >> /etc/sysctl.conf
sysctl -p
reboot
```

## Installation of the web server

Install a web reserve proxy software (e.g., nginx)

```shell
apt-get install nginx
```

Put the ```index.html``` to the web directory(/var/www/html)

If you want to save and leverage the test history, install a database (such as SQLite/MySQL) and run ```install.sql```, put ```saveData.php, getData.php``` to the web directory.


<!--

## 部署tcp_fastbts模块

推荐使用ubuntu系统，内核版本5.0.1

内核安装:
```shell
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-headers-5.0.1-050001_5.0.1-050001.201903100732_all.deb
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-headers-5.0.1-050001-generic_5.0.1-050001.201903100732_amd64.deb
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-image-unsigned-5.0.1-050001-generic_5.0.1-050001.201903100732_amd64.deb
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v5.0.1/linux-modules-5.0.1-050001-generic_5.0.1-050001.201903100732_amd64.deb
sudo dpkg -i ***.deb
```

删除其他内核（或切换启动顺序）
```shell
dpkg --get-selections| grep linux
sudo apt-get remove [your old kernels]
```

编译安装 tcp_fastbts
```shell
make
make install
```

将拥塞控制算法切换到 tcp_fastbts
```shell
echo "" >/etc/sysctl.conf
echo "net.core.default_qdisc=fq" >> /etc/sysctl.conf
echo "net.ipv4.tcp_congestion_control=fastbts" >> /etc/sysctl.conf
sysctl -p
reboot
```

-->