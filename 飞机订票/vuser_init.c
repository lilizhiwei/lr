/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 8859
   ------------------------------------------------------------------------------- */

vuser_init()
{   
//<input type=hidden name=userSession value=123431.481571486zDtQAAzpiDDDDDDDDiAQtpAtV>

// 	web_reg_save_param("userSession",
// 		"LB/IC=<input type=hidden name=userSession value=", //����LB/IC��ʾ���Դ�Сд���
// 		"RB=>",
// 		"NotFound=WARNING", //��ʾ��û���������ұ߽������ʱ����
// 		"Search=Body", //��ʾ�Ӻ����������Ӧ�����head�м���
// 		LAST);

// 	web_reg_save_param("userSession",
// 		"LB=<input type=hidden name=userSession value=",
// 		"RB=",
// 		"Ord=ALL", //��ʾ���Ҳ����������������ұ߽�Ľ��
// 		"Search=head", //��ʾ�Ӻ����������Ӧ�����head�м���
// 		LAST);

// 	web_reg_save_param("session",  
// 		"LB=<input type=hidden name=userSession value=",
// 		"RB=>",
// 		"Ord=1",  //��ʾ�����Ҳ������һ���������ұ߽�Ľ��
// 		"SaveOffset=4", //��ʾ�������ұ߽������Ľ���ĵ�5���ַ���ʼ������
// 		"NotFound=ERROR",//��ʾ��û���������ұ߽������ʱ����
// 		"Search=All", //��ʾ�Ӻ��������������Ӧ����м���
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

// 	web_reg_find("Text={login_name}",  //��ʾ�����ı��Ƕ�̬�Ĳ���ֵ�û���
// 		LAST);


	web_reg_find("TextPfx=Welcome, <b>",   //��ʾ��������ǰ׺��Welcome, <b>
		"TextSfx=</b>",    //��ʾ�������ݺ�׺��</b>
		"Fail=NotFound",   //��ʾ���������Ҳ���ʱ����
		"SaveCount=check", //��ʾ���ҵ��ļ�������������洢Ϊcheck����
		"Search=Body",     //��ʾ���ķ�Χ��Body
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
