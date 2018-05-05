/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 8859
   ------------------------------------------------------------------------------- */

vuser_init()
{   
//<input type=hidden name=userSession value=123431.481571486zDtQAAzpiDDDDDDDDiAQtpAtV>

// 	web_reg_save_param("userSession",
// 		"LB/IC=<input type=hidden name=userSession value=", //设置LB/IC表示忽略大小写检查
// 		"RB=>",
// 		"NotFound=WARNING", //表示当没有满足左右边界的内容时报错
// 		"Search=Body", //表示从后面请求的响应结果的head中检索
// 		LAST);

// 	web_reg_save_param("userSession",
// 		"LB=<input type=hidden name=userSession value=",
// 		"RB=",
// 		"Ord=ALL", //表示查找并保存所有满足左右边界的结果
// 		"Search=head", //表示从后面请求的响应结果的head中检索
// 		LAST);

// 	web_reg_save_param("session",  
// 		"LB=<input type=hidden name=userSession value=",
// 		"RB=>",
// 		"Ord=1",  //表示仅查找并保存第一个满足左右边界的结果
// 		"SaveOffset=4", //表示满足左右边界条件的结果的第5个字符开始的内容
// 		"NotFound=ERROR",//表示当没有满足左右边界的内容时报错
// 		"Search=All", //表示从后面请求的所有响应结果中检索
// 		LAST);

	web_reg_save_param("session",
		"LB=<input type=hidden name=userSession value=",
		"RB=>",
		"Ord=1",
		"NotFound=ERROR",
		LAST);

	web_url("WebTours",
		"URL=http://{url}/WebTours/",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTML",
		LAST);

	lr_output_message(lr_eval_string("{session1},{session}"));

	lr_think_time(26);

// 	web_reg_find("Text={login_name}",  //表示检查的文本是动态的参数值用户名
// 		LAST);


	web_reg_find("TextPfx=Welcome, <b>",   //表示检查的内容前缀是Welcome, <b>
		"TextSfx=</b>",    //表示检查的内容后缀的</b>
		"Fail=NotFound",   //表示检查的内容找不到时报错
		"SaveCount=check", //表示查找到的检查结果的数据量存储为check变量
		"Search=Body",     //表示检查的范围是Body
		LAST);

	web_submit_data("login.pl",
		"Action=http://{url}/WebTours/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{url}/WebTours/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={session}", ENDITEM,
		"Name=username", "Value={login_name}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=on", ENDITEM,
		"Name=login.x", "Value=47", ENDITEM,
		"Name=login.y", "Value=14", ENDITEM,
		LAST);

return 0;
}
