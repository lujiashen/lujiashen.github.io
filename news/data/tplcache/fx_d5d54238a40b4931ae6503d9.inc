<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gbk" />
<title>�����ƹ� - ��Ա���� -<?php echo $cfg_webname; ?></title>
<script language="JavaScript" src="templets/images/jquery.js"></script>
<script language="JavaScript" src="templets/images/jquery.lazyload.js"></script>
<script language="JavaScript" src="templets/images/common.js"></script>
<script type="text/javascript" src="templets/js/j.js"></script>
<script type="text/javascript" language='javascript'src='templets/js/main.js'></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/calendar/calendar.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>
</head>
<body>
<?php include(DEDEMEMBER."/templets/head.htm"); ?>
<div class="main">
  <div class="navbar"> <span class="notice"><a href="/member">λ��</a></span>
    <ul class="position">
      <li><a href="/">��ҳ</a></li>
       <li><a href="/member">��Ա����</a></li>
  <li style="background-image: none; background-position: initial initial; background-repeat: initial initial;">�����ƹ�</li>
    </ul>
  </div>
  <!--navbar end-->
  <div class="ucbox">
    <?php include(DEDEMEMBER."/templets/left.htm"); ?>
     <div class="ucright">
      <div class="listnav">
        <ul class="navclass">
          <li><a href="fx.php" class="selected">�����ƹ�</a></li>
        </ul>
      </div>
      <!--listnav end-->
    
      <div class="extend">
        <div class="uccontact"> <span class="ltitle1">�����ƹ�</span> <span class="ltbg"></span>
        
        <ul class="extfont">
    <li>1�����������������ӣ�ͨ����̳��QQ����վ����ʽ����ת��������������ͨ�������ӷ���վ�㣻</li>
    <li>3���ɴ������������ӷ�����վ�����ɹ�ע���Ա���������<cite>1���</cite>�Ľ�����</li>
    <li>2����վ���жԱ��ƹ�Ľ���Ȩ</li>    
    </ul>
     <ul class="extform">
 <li><span>�ƹ�����1</span><p><input name="" type="text"  class="extinput" value="<?php echo $cfg_basehost; ?>/member/reg_new.php?fromid=<?php echo $cfg_ml->M_ID;?>"/></p><a href="javascript:void(0)"  id="copy-buttonA" data-clipboard-text="<?php echo $cfg_basehost; ?>/member/reg_new.php?fromid=<?php echo $cfg_ml->M_ID;?>" >����</a></li>
    <li><span>�ƹ�����2</span><p><input name="" type="text"  class="extinput" value="<?php echo $cfg_basehost; ?>/member/reg_new.php?fromuser=<?php echo $cfg_ml->M_LoginID;?>" /></p><a href="javascript:void(0)"  id="copy-buttonB" data-clipboard-text="<?php echo $cfg_basehost; ?>/member/reg_new.php?fromuser=<?php echo $cfg_ml->M_LoginID;?>" >����</a></li>
    
    </ul>
        </div>
        <!--uccontact end--> 
        
      </div>
      <!--extend end--> 
      
    </div>
    <!--urright end--> 
    
  </div>
  <!--ucbox end--> 
  
</div> 
<!--main end-->
 
<?php include(DEDEMEMBER."/templets/foot.htm"); ?>

<script language="JavaScript" src="templets/js/ZeroClipboard.js"></script>
<script>
var client = new ZeroClipboard( document.getElementById("copy-buttonA") );
client.on( "ready", function( readyEvent ) {
  client.on( "aftercopy", function( event ) {
    alert('�ƹ��ַ���Ƴɹ�');
  } );
} );

var clientA = new ZeroClipboard( document.getElementById("copy-buttonB") );
clientA.on( "ready", function( readyEvent ) {
  clientA.on( "aftercopy", function( event ) {
    alert('�ƹ��ַ���Ƴɹ�');
  } );
} );
</script>
</body>
</html>