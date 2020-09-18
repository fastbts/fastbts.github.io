<?php
header("Content-type: text/html; charset:utf-8");
header("Content-Type: text/html; charset=utf-8");
$uip=$_SERVER['REMOTE_ADDR'];
$sysid=$_POST['sysid'];
$servername = "127.0.0.1";
$username = "root";
$password = "";
$dbname = "speedtest";
$conn = new mysqli($servername,$username,$password,$dbname);
$time=date('Y-m-d H:i:s');
if($sysid==0){
	$ping=$_POST['ping'];
	$sip=$_POST['sip'];
	$XFresult=$_POST['ATTresult'];
	$sql ="INSERT INTO data0(uip,sip,ping,ATTresult,time) VALUES('$uip','$sip','$ping',$ATTresult,'$time')";
	$result = $conn->query($sql);
}else if($sysid==1){
	$ping=$_POST['ping'];
	$sip=$_POST['sip'];
	$Sresult=$_POST['Sresult'];
	$sql ="INSERT INTO data2(uip,sip,ping,Sresult,time) VALUES('$uip','$sip','$ping',$Sresult,'$time')";
	$result = $conn->query($sql);
}else if($sysid==2){
	$ping=$_POST['ping'];
	$sip=$_POST['sip'];
	$Bresult=$_POST['Bresult'];
	$sql ="INSERT INTO data2(uip,sip,ping,Bresult,time) VALUES('$uip','$sip','$ping',$Bresult,'$time')";
	$result = $conn->query($sql);
}else if($sysid==4){
	$ping=$_POST['ping'];
	$sip=$_POST['sip'];
	$SFresult=$_POST['SFresult'];
	$sql ="INSERT INTO data4(uip,sip,ping,SFresult,time) VALUES('$uip','$sip','$ping',$SFresult,'$time')";
	$result = $conn->query($sql);
}else if($sysid==5){
	$ping=$_POST['ping'];
	$sip=$_POST['sip'];
	$speed=$_POST['speed'];
	$count=$_POST['count'];
	$sql ="INSERT INTO data5(uip,sip,ping,speed,count,time) VALUES('$uip','$sip','$ping','$speed',$count,'$time')";
	$result = $conn->query($sql);
}else if($sysid==6){
	$ping=$_POST['ping'];
	$sip=$_POST['sip'];
	$speed=$_POST['speed'];
	$count=$_POST['count'];
	$sql ="INSERT INTO data6(uip,sip,ping,speed,count,time) VALUES('$uip','$sip','$ping','$speed',$count,'$time')";
	$result = $conn->query($sql);
}else if($sysid==7){
	$ping=$_POST['ping'];
	$exping=$_POST['exping'];
	$sip=$_POST['sip'];
	$speed=$_POST['speed'];
	$count=$_POST['count'];
	$EV=$_POST['EV'];
	$sql ="INSERT INTO data7(uip,sip,ping,exping,ev,speed,count,time) VALUES('$uip','$sip','$ping','$exping','$EV','$speed',$count,'$time')";
	$result = $conn->query($sql);
}else if($sysid==8){
	$ping=$_POST['ping'];
	$sip=$_POST['sip'];
	$XFresult=$_POST['XFresult'];
	$sql ="INSERT INTO data8(uip,sip,ping,XFresult,time) VALUES('$uip','$sip','$ping',$XFresult,'$time')";
	$result = $conn->query($sql);
}
$conn->close();
?>
