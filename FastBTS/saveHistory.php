<?php
header("Content-type: text/html; charset:utf-8");
header("Content-Type: text/html;charset=utf-8");
$uip=$_SERVER['REMOTE_ADDR'];
$count=$_POST['count'];
$ping=explode(" ",$_POST['ping']);
$speed=explode(" ",$_POST['speed']);
$sip=explode(" ",$_POST['sip']);
echo "count=".$count;
print_r($ping);
print_r($speed);
print_r($sip);
$servername = "127.0.0.1";
$username = "root";
$password = "";
$dbname = "speedtest";
$conn = new mysqli($servername,$username,$password,$dbname);
$time=date('Y-m-d H:i:s');
for($i=0;$i<$count;$i++){
	$p=$ping[$i];
	$v=$speed[$i];
	$sql ="INSERT INTO history".$sip[$i]."(ping,speed,uip,time) VALUES($p,$v,'$uip','$time')";
	echo $sql;
	$result = $conn->query($sql);
}
$conn->close();
?>