<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gbk" />
<title><?php echo $GLOBALS['_vars']['spacename'];  echo $GLOBALS['_vars']['curtitle']; ?></title>
<meta name="author" content="<?php echo $GLOBALS['_vars']['uname']; ?>"/>
<script src="/web/m/jquery.min.js" type="text/javascript"></script>
<script src="/web/m/v2js.js" type="text/javascript"></script>
<link href="/web/m/css.css" rel="stylesheet">
</head>
<body>
<div id="top">
  <div class="w960">
    <div class="logo"><a href="/" >������+</a></div>
    <div class="top_c"></div>
    <?php
//δ��¼��ʾ��head
if(!$cfg_ml->IsLogin()) {
?>
    <div class="top_r"> 
      ���ã�<a href="/member/login.php">��¼</a> <a href="./member/index_do.php?fmdo=user&dopost=regnew">ע��</a> </div>
    <?php
}
//��¼����ʾ��head
else {
?>
    <div class="top_r"> 
      ���ã�<a href="<?php echo $myurl; ?>"><?php echo $cfg_ml->M_UserName?></a> <a href="/member/zl.php">����</a> <a href="../member/index_do.php?fmdo=login&dopost=exit">ע��</a> </div>
    <?php
}
?>
  </div>
</div>
<div id="main">
<div class="layout-head w960">
  <div class="head-info">
    <h1><?php echo $GLOBALS['_vars']['spacename']; ?></h1>
    <div class="head-description"><?php echo $GLOBALS['_vars']['sign']; ?></div>
  </div>
</div>
<div class="head_nav">
  <div class="nav_bg"></div>
  <div class="w960">
    <div class="head-name"><span class="user-name textoverflow"><?php echo $GLOBALS['_vars']['uname']; ?></span>
      <div class="head-description"><?php echo $myurl; ?></div>
    </div>
    <div class="actions"> </div>
    <ul>
      <li><a href="index.php?uid=<?php echo $GLOBALS['_vars']['userid_e']; ?>">��ҳ</a></li>
      <li><a href="index.php?uid=<?php echo $GLOBALS['_vars']['userid_e']; ?>&action=article">����</a></li>
      <?php
		foreach($_vars['bloglinks'] as $k=>$v)
		{
			if($k==2) {
				echo "		<li><a href=\"index.php?uid={$_vars['userid_e']}&action=album\">���</a></li>\r\n";
			}
			else {
				echo "		<li><a href=\"index.php?uid={$_vars['userid_e']}&action=archives&channelid={$k}\">{$v}</a></li>\r\n";
			}
		}
		?>
      <li><a href="index.php?uid=<?php echo $GLOBALS['_vars']['userid_e']; ?>&action=infos">����</a></li>
      <li><a href="index.php?uid=<?php echo $GLOBALS['_vars']['userid_e']; ?>&action=guestbook">����</a></li>
      <li class="fk"></li>
    </ul>
    <div class="head-avatar"><?php if($_vars['face']==''){ ?> <img src="space/person/common/images/noavatar.gif" alt="<?php echo $row['uname']; ?>��û����ͷ��" /> <?php
}
else{
?> <img src="<?php echo $GLOBALS['_vars']['face']; ?>" alt="<?php echo $GLOBALS['_vars']['uname']; ?>��ͷ��" /> <?php } ?></div>
    <?php 
            	if($_vars['userid']==$cfg_ml->M_LoginID){
            		echo "  <div class='sztx'></div>
    <a href='/member/tx.php' class='sztx'>�޸�ͷ��</a> ";
             	}
            ?>
  </div>
</div>