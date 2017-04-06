Action()
{

	web_add_cookie("pt2gguin=o1548790965; DOMAIN=s.pc.qq.com");

	web_add_cookie("RK=LgU3ze17eC; DOMAIN=s.pc.qq.com");

	web_add_cookie("ptcz=9ca2dfb822523dae4869a717ba29a20df4b7d91e9542b59930c2b3e6678517b2; DOMAIN=s.pc.qq.com");

	web_add_cookie("ptui_loginuin=194772385; DOMAIN=s.pc.qq.com");

	web_add_cookie("pt2gguin=o1548790965; DOMAIN=c.gj.qq.com");

	web_add_cookie("RK=LgU3ze17eC; DOMAIN=c.gj.qq.com");

	web_add_cookie("ptcz=9ca2dfb822523dae4869a717ba29a20df4b7d91e9542b59930c2b3e6678517b2; DOMAIN=c.gj.qq.com");

	web_add_cookie("ptui_loginuin=194772385; DOMAIN=c.gj.qq.com");

//Correlation comment - Do not change! Original value='HpQDHf' Name ='CorrelationParameter_1'
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_1",
		"LB=t",
		"RB=D",
		"Ordinal=3",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/nav.pl*",
		LAST);
//Correlation comment - Do not change! Original value='iHzcf' Name ='CorrelationParameter_2'
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_2",
		"LB=z",
		"RB=>\n<table border",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/nav.pl*",
		LAST);
	web_reg_find("Search=Body",
		"Text=Web Tours",
		LAST);
	web_url("WebTours",
		"URL=http://localhost:1080/WebTours/",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://s.pc.qq.com/navigate/adc/adc_loader.js?v=20160326171611", ENDITEM,
		"URL=http://s.pc.qq.com/navigate/adc/v3/engine_loader_v3.js", ENDITEM,
		"URL=http://s.pc.qq.com/navigate/adc/json2.js", ENDITEM,
		"URL=http://s.pc.qq.com/navigate/adc/jquery.min.js?ver=3", ENDITEM,
		"URL=http://c.gj.qq.com/fcgi-bin/microreport?gjguid=5dc8552377fffed4c9e553f9395a5e18&type=10&reserve1=2&bid=1&rand=0.9214218282663475&refer=http%3A%2F%2Flocalhost%3A1080%2FWebTours%2F&reserve3=348832", ENDITEM,
		"URL=http://s.pc.qq.com/navigate/adc/velocity.js", ENDITEM,
		LAST);

	lr_think_time(9);

	lr_start_transaction("login");

	web_submit_data("login.pl",
		"Action=http://localhost:1080/WebTours/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/WebTours/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value=120815.512758202zcVttt{CorrelationParameter_1}DHcizpz{CorrelationParameter_2}", ENDITEM,
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=JSFormSubmit", "Value=on", ENDITEM,
		"Name=login.x", "Value=54", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		LAST);

	lr_end_transaction("login", LR_AUTO);

	web_url("Search Flights Button",
		"URL=http://localhost:1080/WebTours/welcome.pl?page=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/WebTours/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_think_time(11);

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/WebTours/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={NewParam}", ENDITEM,
		"Name=departDate", "Value=04/07/2017", ENDITEM,
		"Name=arrive", "Value=Denver", ENDITEM,
		"Name=returnDate", "Value=04/08/2017", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=32", ENDITEM,
		"Name=findFlights.y", "Value=11", ENDITEM,
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/WebTours/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value=203;277;04/07/2017", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=reserveFlights.x", "Value=37", ENDITEM,
		"Name=reserveFlights.y", "Value=5", ENDITEM,
		LAST);

	lr_think_time(4);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/WebTours/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value=Joseph", ENDITEM,
		"Name=lastName", "Value=Marshall", ENDITEM,
		"Name=address1", "Value=234 Willow Drive", ENDITEM,
		"Name=address2", "Value=San Jose/CA/94085", ENDITEM,
		"Name=pass1", "Value=Joseph Marshall", ENDITEM,
		"Name=creditCard", "Value=5341351653", ENDITEM,
		"Name=expDate", "Value=", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=outboundFlight", "Value=203;277;04/07/2017", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=56", ENDITEM,
		"Name=buyFlights.y", "Value=12", ENDITEM,
		LAST);

	web_url("SignOff Button",
		"URL=http://localhost:1080/WebTours/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/WebTours/nav.pl?page=menu&in=flights",
		"Snapshot=t7.inf",
		"Mode=HTML",
		LAST);

return 0;
}
