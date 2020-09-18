<?php
header("Content-type: text/html; charset:utf-8");
header("Content-Type: text/html;charset=utf-8");
$uip=$_SERVER['REMOTE_ADDR'];
//$ping=$_POST['ping'];
$ping=explode(" ",$_POST['ping']);
$servername = "127.0.0.1";
$username = "root";
$password = "";
$dbname = "speedtest";
$conn = new mysqli($servername,$username,$password,$dbname);
$EV=array();
$EVM=array();
$inf=1000;
for($suf=0;$suf<30;$suf++){
	$sql ="SELECT * FROM history$suf order by ping";
	$result = $conn->query($sql);// 执行语句
	$hisP=array();
	$hisV=array();
//	echo $sql;
	while($row=$result->fetch_row()){
		array_push($hisP,$row[0]);
		array_push($hisV,$row[1]);
	}
	$center=$ping[$suf];
	$dis=array();
	foreach($hisP as $p){
		array_push($dis,max(1,abs($p-$center)));
	}
	if(count($dis)==0){
		array_push($EV,$inf);	
		array_push($EVM,1);	
		continue;
	}
	sort($dis);
	$bestdis=$dis[0];
	$density=1/$dis[0];
	for($i=0;$i<count($dis);$i++){
		if(($i+1)/$dis[$i]>=$density){
			$density=($i+1)/$dis[$i];
			$bestdis=$dis[$i];
		}
	}
	$sum=0;
	$cnt=0;
	$ma=0;
	for($i=0;$i<count($hisV);$i++){
		if(abs($hisP[$i]-$center)<=$bestdis){
			$sum+=$hisV[$i];
			$cnt+=1;
			$ma=max($ma,$hisV[$i]);
		}
	}
	array_push($EV,$sum/$cnt);	
	array_push($EVM,$ma);	
}
$rtn=array();
$rtn["ev"]=$EV;
$rtn["evMax"]=$EVM;
echo json_encode($rtn);
$conn->close();
?>