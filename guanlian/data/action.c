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

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://s.pc.qq.com/navigate/adc/adc_loader.js?v=20160326171611", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/v3/engine_loader_v3.js", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/json2.js", ENDITEM, 
		"Url=http://c.gj.qq.com/fcgi-bin/microreport?gjguid=5dc8552377fffed4c9e553f9395a5e18&type=10&reserve1=2&bid=1&rand=0.5448980330120898&refer=http%3A%2F%2Flocalhost%3A1080%2FWebTours%2F&reserve3=348832", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/jquery.min.js?ver=3", ENDITEM, 
		"Url=http://s.pc.qq.com/navigate/adc/velocity.js", ENDITEM, 
		LAST);

	lr_think_time(8);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=120815.482948562zcVtttzptAtVzzzHDHcizpzHitcf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=login.x", "Value=34", ENDITEM, 
		"Name=login.y", "Value=8", ENDITEM, 
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/WebTours/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}