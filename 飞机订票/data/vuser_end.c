vuser_end()
{

	lr_think_time(17);

	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/WebTours/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}