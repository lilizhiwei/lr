Action()
{
//�������ͱ��������ڱ��������
	int i;

//�������ͱ��������ڱ��淵������
    int j;

//���ȡֵ1-4֮�䣨��Ʊѡ��ֻ�����
	i=rand()%4+1;

//��ֵ��������=�������+i��
	j= atoi(lr_eval_string("{DD}"))+i;
	
//�ж����ڳ���30�������30
	if(j>30){
		j=30;
	}

//�������ֵΪ����random
	lr_save_int(i, "random");

//�������������Ϊ����rDate
	lr_save_int(j, "rDate");

//���ƴ�ӵ����ڣ���֤�Ƿ�����������Ԥ�����
	lr_output_message("�������-��������:%s", lr_eval_string("{MM}/{DD}/2018~{MM}/{rDate}/2018"));


	lr_start_transaction("��һ������˵�");

	lr_think_time(40);

	web_url("welcome.pl",
		"URL=http://{url}/WebTours/welcome.pl?page=search",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{url}/WebTours/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("��һ������˵�", LR_AUTO);

	lr_start_transaction("�ڶ���ѡ��Ʊ��Ϣ");

	lr_think_time(133);

//Correlation comment - Do not change! Original value='130;470;04/16/2018 ' Name ='CorrelationParameter_1'
// 	web_reg_save_param_ex(
// 		"ParamName=CorrelationParameter_1",
// 		"LB=outboundFlight value=",
// 		"RB=checked ",
// 		SEARCH_FILTERS,
// 		"Scope=All",
// 		"IgnoreRedirections=Yes",
// 		"RequestUrl=*/reservations.pl*",
// 		LAST);


	//������ɼ�������м���ύ�Ƿ�ɹ�
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"SaveCount=check_2",
		"Text=Flight departing from <B>{depart}</B> to <B>{arrive}</B> ",
		LAST);

	web_reg_save_param("outboundFlight",
		"LB=name=outboundFlight value=",
		"RB=>",
		"Ord={random}",
		"NotFound=ERROR",
		"SaveLen=18",
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://{url}/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{url}/WebTours/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={depart}", ENDITEM,
		"Name=departDate", "Value={MM}/{DD}/2018", ENDITEM,
		"Name=arrive", "Value={arrive}", ENDITEM,
		"Name=returnDate", "Value={MM}/{rDate}/2018", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=62", ENDITEM,
		"Name=findFlights.y", "Value=11", ENDITEM,
		LAST);

	if(atoi(lr_eval_string("{check_2}"))>0){

		lr_end_transaction("�ڶ���ѡ��Ʊ��Ϣ", LR_PASS);

	}
	else{
		lr_end_transaction("�ڶ���ѡ��Ʊ��Ϣ", LR_FAIL);
		return 0;
	}


	lr_start_transaction("������ѡ�����ʱ��");

	lr_think_time(42);

    //���ݼ���Ƿ���ڽ���ж��Ƿ�ɹ�    
	web_reg_find("TextPfx=ticket(s) is = $",
		"TextSfx=<tr>",
		"Search=Body",
		"SaveCount=check_3",
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://{url}/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{url}/WebTours/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatPref}", ENDITEM,
		"Name=seatPref", "Value={seatType}", ENDITEM,
		"Name=reserveFlights.x", "Value=55", ENDITEM,
		"Name=reserveFlights.y", "Value=11", ENDITEM,
		LAST);

	if(atoi(lr_eval_string("{check_3}"))>0){

		lr_end_transaction("������ѡ�����ʱ��", LR_PASS);

	}
	else{
		lr_end_transaction("������ѡ�����ʱ��", LR_FAIL);
		return 0;
	}

	lr_start_transaction("���Ĳ��ύ�˿���Ϣ");

	lr_think_time(127);

//Correlation comment - Do not change! Original value='130;470;04/16/2018 ' Name ='CorrelationParameter_1'

    //���ݹ����������ѽ���жϽ����Ƿ�ɹ�
	web_reg_save_param("total_cost",
		"LB=<b> $",
		"RB= </b>",
		"Ord=1",
		"NotFound=ERROR",
		LAST);


	//��λ����
// 	web_reg_save_param("total_cost",
// 		"LB=    <TD > Total Cost /r/n"
// 		"    </TD> /r/n"
// 		"    <TD> /r/n"
// 		"       <b> $",
// 		"RB= </b>",
// 		"Ord=1",
// 		"NotFound=ERROR",
// 		LAST);


	web_submit_data("reservations.pl_3",
		"Action=http://{url}/WebTours/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{url}/WebTours/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstname}", ENDITEM,
		"Name=lastName", "Value={lastname}", ENDITEM,
		"Name=address1", "Value=234 Willow Drive", ENDITEM,
		"Name=address2", "Value=San Jose/CA/94085", ENDITEM,
		"Name=pass1", "Value=Joseph Marshall", ENDITEM,
		"Name=creditCard", "Value={cardno}", ENDITEM,
		"Name=expDate", "Value=02/29", ENDITEM,
		"Name=saveCC", "Value=on", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatPref}", ENDITEM,
		"Name=seatPref", "Value={seatType}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=39", ENDITEM,
		"Name=buyFlights.y", "Value=7", ENDITEM,
		LAST);

	if(atoi(lr_eval_string("{total_cost}"))>0){

	lr_end_transaction("���Ĳ��ύ�˿���Ϣ", LR_PASS);
	}
    else{
	lr_end_transaction("���Ĳ��ύ�˿���Ϣ", LR_FAIL);
	}

	

return 0;
}
