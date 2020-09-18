# Fast and Light Bandwidth Testing for Internet Users
### Introduction
Bandwidth testing measures the access bandwidth of end hosts, which is crucial to emerging Internet applications for network-aware content delivery. However, today's bandwidth testing services (BTSes) are slow and costly---the tests take a long time to run, consume excessive data usage at the client side, and/or require large-scale test server deployments. The inefficiency and high cost of BTSes root in their methodologies that use excessive temporal and spatial redundancies for combating noises in Internet measurement. This paper presents FastBTS to make BTS fast and cheap while maintaining high accuracy. The key idea of FastBTS is to accommodate and exploit the noise rather than repetitively and exhaustively suppress the impact of noise. This is achieved by a novel statistical sampling framework (termed fuzzy rejection sampling). We build FastBTS as an end-to-end BTS that implements fuzzy rejection sampling based on elastic bandwidth probing and denoised sampling from high-fidelity windows, together with server selection and multi-homing support. Our evaluation shows that with only 30 test servers, FastBTS achieves the same level of accuracy compared to the state-of-the-art BTS (SpeedTest.net) that deploys ∼ 12,000 servers. Most importantly, FastBTS makes bandwidth tests 5.6× faster and 10.7× more data-efficient.

### FastBTS We Implement

<style>
table th:nth-of-type(1) {
    width: 100px;
    max-width:100px;
    min-width:100px;
}
</style>

|BTS|Implementation|
|:----:|------|
|FastBTS|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/FastBTS](https://github.com/fastbts/fastbts.github.io/tree/master/FastBTS)|


### Representitive Commercial BTSes

|BTS|Website|Our Implementation|
|:----:|------|------|
|SpeedOf|[https://speedof.me](https://speedof.me/)|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/Speedof.me/](https://github.com/fastbts/fastbts.github.io/tree/master/Speedof.me/)|
|BWP|[https://www.bandwidthplace.com](https://www.bandwidthplace.com/)|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/BandwidthPlace](https://github.com/fastbts/fastbts.github.io/tree/master/BandwidthPlace/)|
|SFtest|[https://sourceforge.net/speedtest](https://sourceforge.net/speedtest/)|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/SourceForge/](https://github.com/fastbts/fastbts.github.io/tree/master/SourceForge/)|
|ATTtest|[http://speedtest.att.com/speedtest](http://speedtest.att.com/speedtest/)|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/ATTSpeedTest/](https://github.com/fastbts/fastbts.github.io/tree/master/ATTSpeedTest/)|
|Xfinity|[http://speedtest.xfinity.com/](http://speedtest.xfinity.com)|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/XFinity/](https://github.com/fastbts/fastbts.github.io/tree/master/XFinity/)|
|FAST|[https://fast.com](https://fast.com)|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/Fast.com](https://github.com/fastbts/fastbts.github.io/tree/master/Fast.com)|
|SpeedTest|[https://speedtest.net](https://speedtest.net)|[https://github.com/fastbts/<br>fastbts.github.io/tree/master/SpeedTest.net](https://github.com/fastbts/fastbts.github.io/tree/master/SpeedTest.net)|
|Android API-A|[source code](https://cs.android.com/android/platform/superproject/+/master:frameworks/base/core/java/android/net/NetworkCapabilities.java;drc=master;bpv=1;bpt=1;l=1114)|-|
|Android API-B|[source code](https://cs.android.com/android/platform/superproject/+/master:frameworks/base /core/tests/bandwidthtests/src/com/android/bandwidthtest/BandwidthTest.java)|-|
|WiFiMaster|[https://en.wifi.com/wifimaster/](https://en.wifi.com/wifimaster/)|-|

### Other Bandwidth Probing Methods



|BTS|Implementation|
|:----:|------|
|TOPP|[https://github.com/fastbts/<br>fastbts.github.io/blob/master/nonFlooding](https://github.com/fastbts/fastbts.github.io/tree/master/nonFlooding)|
|IGI|[https://github.com/fastbts/<br>fastbts.github.io/blob/master/nonFlooding](https://github.com/fastbts/fastbts.github.io/tree/master/nonFlooding)|
|PathChirp|[https://github.com/fastbts/<br>fastbts.github.io/blob/master/nonFlooding](https://github.com/fastbts/fastbts.github.io/tree/master/nonFlooding)|


