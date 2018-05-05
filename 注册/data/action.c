Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		LAST);

	web_url("header.html", 
		"URL=http://localhost:1080/WebTours/header.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Mode=HTML", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/WebTours/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("开始注册");

	lr_think_time(13);

	web_url("login.pl", 
		"URL=http://localhost:1080/WebTours/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("geturl.php", 
		"URL=http://config.pinyin.sogou.com/api/toolbox/geturl.php?h=830FD8C8F2913F77CBA929C181CAA603&v=8.9.0.2223&r=0000_sogou_pinyin_74", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Mode=HTML", 
		LAST);

	lr_think_time(15);

	web_submit_data("login.pl_2", 
		"Action=http://localhost:1080/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=jojo10", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=passwordConfirm", "Value=bean", ENDITEM, 
		"Name=firstName", "Value=10", ENDITEM, 
		"Name=lastName", "Value=10", ENDITEM, 
		"Name=address1", "Value=10", ENDITEM, 
		"Name=address2", "Value=10", ENDITEM, 
		"Name=register.x", "Value=62", ENDITEM, 
		"Name=register.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("开始注册",LR_AUTO);

	lr_think_time(15);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/WebTours/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(12);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/WebTours/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}