<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>" />
<title>�ĵ����� - ��Ա���� -<?php echo $cfg_webname; ?></title>
<link href="templets/style/base.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/j.js"></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/table_function.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>
<script language="JavaScript" src="templets/images/jquery.js"></script>
<script language="JavaScript" src="templets/images/jquery.lazyload.js"></script>
<script language="JavaScript" src="templets/images/common.js"></script>
<script type="text/javascript">
  function viewArc(aid){
	  window.open("<?php echo $GLOBALS['cfg_phpurl']; ?>/view.php?aid="+aid);
  }
  function editArc(aid,channelid){
	  location = "archives_do.php?dopost=edit&channelid="+channelid+"&aid="+aid;
  }
  function delArc(aid){
	  if(window.confirm('��ȷ��Ҫɾ����ƪ�ĵ���?')) location="archives_do.php?aid="+aid+"&dopost=delArc";
  }
</script>
</head>
<body>
<?php include(DEDEMEMBER."/templets/head.htm"); ?>
<div class="main">
  <div class="navbar"> <span class="notice"><a href="/member">λ��</a></span>
    <ul class="position">
      <li><a href="/">��ҳ</a></li>
      <li><a href="/member">��Ա����</a></li>
      <li style="background-image: none; background-position: initial initial; background-repeat: initial initial;">�ĵ�����</li>
    </ul>
  </div>
  <!--navbar end-->
  <div class="ucbox">
    <?php include(DEDEMEMBER."/templets/left.htm"); ?>
    <div class="ucright">
      <div class="listnav">
        <ul class="navclass">
          <li style="background-image: none; background-position: initial initial; background-repeat: initial initial;"><a href="operation.php" class="selected">�ĵ�����</a></li>
        </ul>
      </div>
      <!--listnav end-->
      <ul class="classnav">
        <li><a href="content_list.php?channelid=<?php echo $channelid;?>" <?php echo ($arcrank=='')? "class='selected'" : "";?>><span>ȫ��</span></a></li>
        <li><a href="content_list.php?channelid=<?php echo $channelid;?>&arcrank=1" <?php echo ($arcrank=='1')? "class='selected'" : "";?>><span>�����</span></a></li>
        <li><a href="content_list.php?channelid=<?php echo $channelid;?>&arcrank=-1" <?php echo ($arcrank=='-1')? "class='selected'" : "";?>><span>δ���</span></a></li>
        <li><a href="content_list.php?channelid=<?php echo $channelid;?>&arcrank=-2" <?php echo ($arcrank=='-2')? "class='selected'" : "";?>><span>���˻�</span></a></li>
      </ul>
      <div class="release"><a href="article_add.php">��ҪͶ��</a></div>
      <div>
     <!--������Ϣ��ʾ -->
		<table width="100%" border="0" cellpadding="0" cellspacing="0">
		<tr>
		<td valign="top">
        <table width="100%" border="0" cellpadding="0" cellspacing="0" class="list" style="font-weight:normal;background:#ffffff;">
          <thead>
            <tr style="background:#f5f5f5;height:36px;">
              <td width="46%" style="text-align:center;">���±���</td>
              <td width="15%" style="text-align:center;">��Ŀ </td>
              <td width="10%" style="text-align:center;">״̬ </td>
              <td width="13%" style="text-align:center;">����ʱ�� </td>
              <td width="26%" style="text-align:center;">����</td>
            </tr>
          </thead>
          <tbody>
          <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
		  
            <tr onmouseover="this.style.backgroundColor='#ffffcc'" onmouseout="this.style.backgroundColor='#ffffff'" style="height:32px;line-height:32px;">
              <td class="tabTitle">
			  <?php
if($fields['arcrank']>=0)
{
?><a href="javascript:viewArc(<?php echo $fields['id']; ?>);" target="_blank"><?php
}else{
?> <a href='javascript:viewArc(<?php echo $fields['id']; ?>);' target='_blank'><?php } ?>��<?php echo $fields['title'];  echo IsPicArchives($fields['litpic']); ?></a></td>
              <td align="center"><?php echo $fields['typename']; ?></td>
              <td align="center"><?php
if($fields['arcrank']>=0) echo "�����";
else if($fields['arcrank']==-2) echo "<font color='blue'>���˻�</font>";
else echo "<font color='red'>δ���</font>";
?></td>
              <td align="center"><?php echo GetDateMk($fields['senddate']); ?></td>
              <td align="center" class="doPost" style="color:#999999;"> <a href="javascript:editArc(<?php echo $fields['id']?>,<?php echo $fields['channel']?>);">�޸�</a> | <a href="javascript:delArc(<?php echo $fields['id']?>);">ɾ��</a> |  
<?php
if($fields['arcrank']>=0)
{
?>  <a href="javascript:viewArc(<?php echo $fields['id']; ?>);" target="_blank">�鿴</a>
<?php
}else{
?><a href='javascript:viewArc(<?php echo $fields['id']; ?>);' target='_blank'>Ԥ��</a>
<?php
}
?>
</td>
            </tr>
         <?php
}
}?>
          </tbody>
          <tfoot>
            <tr>
              <td colspan="6"><div class="pageList" style="height:43px;padding-right:15px;padding-top:5px;"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div></td>
            </tr>
          </tfoot>
        </table>
		</td>
		</tr>
		</table>
      </div>
      <div class="pagebox">
        <!--page end--> 
        
      </div>
      <?php if($autoi==1){?>
      <div class="noneinfo"> <span><img src="templets/images/um01.png" alt="����û�з�����Ʒ" /></span>
        <div class="umbg">
          <h2>��Ӵ������û�з���<?php echo $positionname; ?>�أ�</h2>
          <p>�����̳̿��Եý��Ŷ���Ͻ���~</p>
          <a href="article_add.php">��Ҫ����<?php echo $positionname; ?></a> </div>
      </div>
      <style>
	.zpadmin,.pagebox{display:none}
	</style>
      <?php }?>
    </div>
    <!--urright end--> 
    
  </div>
  <!--ucbox end--> 
  
</div>
<?php include(DEDEMEMBER."/templets/foot.htm"); ?>
</body>
</html>