CREATE DATABASE speedtest;
USE speedtest;
CREATE TABLE data0(
	uip VARCHAR(100),
	sip VARCHAR(100),
	ping VARCHAR(1000),
	ATTresult DOUBLE,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data1(
	uip VARCHAR(100),
	sip VARCHAR(100),
	ping VARCHAR(1000),
	Sresult DOUBLE,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data2(
	uip VARCHAR(100),
	sip VARCHAR(100),
	ping VARCHAR(1000),
	Bresult DOUBLE,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data4(
	uip VARCHAR(100),
	sip VARCHAR(1000),
	ping VARCHAR(1000),
	SFresult DOUBLE,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data5(
	uip VARCHAR(100),
	sip VARCHAR(1000),
	ping VARCHAR(1000),
	speed TEXT,
	count INT,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data6(
	uip VARCHAR(100),
	sip VARCHAR(1000),
	ping VARCHAR(1000),
	speed TEXT,
	count INT,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data7(
	uip VARCHAR(100),
	sip VARCHAR(1000),
	ping VARCHAR(1000),
	exping VARCHAR(6000),
	ev VARCHAR(6000),
	speed TEXT,
	count INT,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data8(
	uip VARCHAR(100),
	sip VARCHAR(100),
	ping VARCHAR(1000),
	XFresult DOUBLE,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE data9(
	uip VARCHAR(100),
	sip VARCHAR(1000),
	ping VARCHAR(1000),
	truth VARCHAR(1000),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history0;
CREATE TABLE history0(
	ping INT,
	uip VARCHAR(100),
	speed DOUBLE,
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history1;
CREATE TABLE history1(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history2;
CREATE TABLE history2(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history3;
CREATE TABLE history3(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history4;
CREATE TABLE history4(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history5;
CREATE TABLE history5(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history6;
CREATE TABLE history6(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history7;
CREATE TABLE history7(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history8;
CREATE TABLE history8(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history9;
CREATE TABLE history9(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history10;
CREATE TABLE history10(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history11;
CREATE TABLE history11(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history12;
CREATE TABLE history12(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history13;
CREATE TABLE history13(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history14;
CREATE TABLE history14(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history15;
CREATE TABLE history15(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history16;
CREATE TABLE history16(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history17;
CREATE TABLE history17(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history18;
CREATE TABLE history18(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history19;
CREATE TABLE history19(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history20;
CREATE TABLE history20(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history21;
CREATE TABLE history21(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history22;
CREATE TABLE history22(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history23;
CREATE TABLE history23(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history24;
CREATE TABLE history24(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history25;
CREATE TABLE history25(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history26;
CREATE TABLE history26(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history27;
CREATE TABLE history27(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history28;
CREATE TABLE history28(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
DROP TABLE history29;
CREATE TABLE history29(
	ping INT,
	speed DOUBLE,
	uip VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
CREATE TABLE spider(
	uip VARCHAR(100),
	id VARCHAR(100),
	speed DOUBLE,
	suf VARCHAR(100),
	time TIMESTAMP
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
