<?php
header("Pragma:no-cache\r\n");
header("Cache-Control:no-cache\r\n");
header("Expires:0\r\n");
header("Content-Type: text/html; charset=gb2312");
//ϵͳ����Ϊά��״̬�ɷ���
$cfg_IsCanView = true;
require_once(dirname(__FILE__)."/config.php");
$cfg_ml = new MemberLogin();
if(empty($cfg_ml->M_ID)){ echo ""; exit(); }
$uid = $cfg_ml->M_LoginID;
?>ff
<?php
$uid = $cfg_ml->M_LoginID;
$user_mid = $cfg_ml->M_ID;
if(!$uid){
?>
<!-- δ��¼״̬ -->
<a href="/member/" class="n1" target="_blank" title="Ͷ��">Ͷ��</a>
<div class="userbar">
<div class="user" id="show_userinfo">
<span class="avatar"><img src="/templets/style/html/images/symbol-25.png"></span>
<a href="javascript:;" class="n4 head-username">��  ��</a>
<ul class="drap">
<li class="i3"><a  href="/member/reg.php" target="_top" class="head-register">ע  ��</a></li>
<li class="i4"><a href="/member/" target="_top"  class="head-login">��  ½</a></li>
</ul>
</div>
</div>
<?php
}else{
?>
<!-- �ѵ�¼״̬ -->
<a href="/member/article_add.php" class="n1" target="_blank" title="Ͷ��">Ͷ��</a>
<div class="userbar">
<div class="user" id="show_userinfo">
<span class="avatar"><img src="/templets/style/html/images/symbol-25.png"></span>
<a href="javascript:;" class="n4 head-username" style="word-spacing:8px; letter-spacing: 1px;"><?php echo $cfg_ml->M_UserName?></a>
<ul class="drap">
<li class="i5"><a  href="/member/" target="_top" class="head-register">��Ա����</a></li>
<li class="i6"><a href="/member/index_do.php?fmdo=login&dopost=exit#" target="_top"  class="head-login">�˳�</a></li>
</ul>
</div>
</div>
<?php
}
?>