Action()
{

//Correlation comment - Do not change! Original value='06318348' Name ='CorrelationParameter_1'

	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_1",
		"LB=120892.0",
		"RB=z",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/nav.pl*",
		LAST);

//Correlation comment - Do not change! Original value='cQftf' Name ='CorrelationParameter_2'

	web_reg_save_param_ex(
		"ParamName=CorrelationParameter_2",
		"LB=p",
		"RB=>\n<table border",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("WebTours",
		"URL=http://192.168.42.4:1080/WebTours/",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTML",
		LAST);

	lr_think_time(13);

    
	lr_start_transaction("login");

	web_submit_data("login.pl",
		"Action=http://192.168.42.4:1080/WebTours/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://192.168.42.4:1080/WebTours/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value=120892.0{CorrelationParameter_1}zcViDicpfHfDHDVAp{CorrelationParameter_2}", ENDITEM,
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=JSFormSubmit", "Value=on", ENDITEM,
		"Name=login.x", "Value=53", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		LAST);

	lr_end_transaction("login", LR_AUTO);

	web_url("SignOff Button",
		"URL=http://192.168.42.4:1080/WebTours/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://192.168.42.4:1080/WebTours/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

return 0;
}
