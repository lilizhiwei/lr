Action()
{

	lr_start_transaction("订票脚本");

//<input type=hidden name=userSession value=122370.621952207zcQttDipizzzzzzHDHHzzpzDDc>

	web_reg_save_param("s_a","LB=name=userSession value=","RB=>",LAST);

	lr_start_transaction("进入订票页面");

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/WebTours/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("进入订票页面", LR_AUTO);

	lr_think_time(7);

	lr_start_transaction("登录");

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={s_a}", ENDITEM, 
		"Name=username", "Value={用户名}", ENDITEM, 
		"Name=password", "Value={密码}", ENDITEM, 
		"Name=login.x", "Value=47", ENDITEM, 
		"Name=login.y", "Value=3", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		LAST);

	lr_end_transaction("登录", LR_AUTO);

	lr_start_transaction("点击订票");

	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:1080/WebTours/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("点击订票", LR_AUTO);

	lr_think_time(11);

//<tr bgcolor=#EFF2F7><td align=center><input type = radio name=outboundFlight value=120;266;11/15/2017 checked >Blue Sky Air 120<td align=center>8am<td align=center>$ 266</TD></TR><tr bgcolor=#EFF2F7><td align=center><input type = radio name=outboundFlight value=121;237;11/15/2017>Blue Sky Air 121<td align=center>1pm<td align=center>$ 237</TD></TR><tr bgcolor=#EFF2F7><td align=center><input type = radio name=outboundFlight value=122;251;11/15/2017>Blue Sky Air 122<td align=center>5pm<td align=center>$ 251</TD></TR><tr bgcolor=#EFF2F7><td align=center><input type = radio name=outboundFlight value=123;217;11/15/2017>Blue Sky Air 123<td align=center>11pm<td align=center>$ 217</TD></TR></table>

	web_reg_save_param("s_s","LB=input type = radio name=outboundFlight value=","RB=;11/15/2017 checked",LAST);

	lr_start_transaction("选择轮班");

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={chu}", ENDITEM, 
		"Name=departDate", "Value=11/15/2017", ENDITEM, 
		"Name=arrive", "Value={chu}", ENDITEM, 
		"Name=returnDate", "Value=11/16/2017", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=40", ENDITEM, 
		"Name=findFlights.y", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("选择轮班", LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("选择票价");

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={s_s};11/15/2017", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=42", ENDITEM, 
		"Name=reserveFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("选择票价", LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("输入订票人信息");

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Joseph", ENDITEM, 
		"Name=lastName", "Value=Marshall", ENDITEM, 
		"Name=address1", "Value=234 Willow Drive", ENDITEM, 
		"Name=address2", "Value=San Jose/CA/94085", ENDITEM, 
		"Name=pass1", "Value=Joseph Marshall", ENDITEM, 
		"Name=creditCard", "Value=123456", ENDITEM, 
		"Name=expDate", "Value=11/14", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value={s_s};11/15/2017", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=buyFlights.x", "Value=31", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("输入订票人信息", LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("确认支付");

	web_submit_data("reservations.pl_4", 
		"Action=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=58", ENDITEM, 
		"Name=Book Another.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("确认支付", LR_AUTO);

	lr_think_time(6);

	lr_start_transaction("退出");

	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/WebTours/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("退出", LR_AUTO);

	lr_end_transaction("订票脚本", LR_AUTO);

	return 0;
}