Action()
{

	web_add_cookie("pt2gguin=o1548790965; DOMAIN=s.pc.qq.com");

	web_add_cookie("RK=LhU3ie1LeC; DOMAIN=s.pc.qq.com");

	web_add_cookie("ptcz=4fe436445ba239f7ee83daa5b69b3f4ac2bbe795bff263bbc513b0d6d3848b33; DOMAIN=s.pc.qq.com");

	web_add_cookie("pt2gguin=o1548790965; DOMAIN=c.gj.qq.com");

	web_add_cookie("RK=LhU3ie1LeC; DOMAIN=c.gj.qq.com");

	web_add_cookie("ptcz=4fe436445ba239f7ee83daa5b69b3f4ac2bbe795bff263bbc513b0d6d3848b33; DOMAIN=c.gj.qq.com");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://s.pc.qq.com/navigate/adc/adc_loader.js?v=20160326171611", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/v3/engine_loader_v3.js", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/json2.js", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/velocity.js", ENDITEM, 
		"Url=http://c.gj.qq.com/fcgi-bin/microreport?gjguid=5dc8552377fffed4c9e553f9395a5e18&type=10&reserve1=2&bid=1&rand=0.14366304993004558&refer=http%3A%2F%2Flocalhost%3A1080%2FWebTours%2F&reserve3=348832", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/jquery.min.js?ver=3", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=55", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(8);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=03/29/2017", ENDITEM, 
		"Name=arrive", "Value=Denver", ENDITEM, 
		"Name=returnDate", "Value=03/30/2017", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=65", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=003;0;03/29/2017", ENDITEM, 
		"Name=reserveFlights.x", "Value=25", ENDITEM, 
		"Name=reserveFlights.y", "Value=13", ENDITEM, 
		LAST);

	lr_think_time(6);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Joseph", ENDITEM, 
		"Name=lastName", "Value=Marshall", ENDITEM, 
		"Name=address1", "Value=234 Willow Drive", ENDITEM, 
		"Name=address2", "Value=San Jose/CA/94085", ENDITEM, 
		"Name=pass1", "Value=Joseph Marshall", ENDITEM, 
		"Name=creditCard", "Value=54631316", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=22", ENDITEM, 
		"Name=buyFlights.y", "Value=15", ENDITEM, 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t7.inf", 
		LAST);

	return 0;
}