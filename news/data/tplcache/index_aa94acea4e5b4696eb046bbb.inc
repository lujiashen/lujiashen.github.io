<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gbk">
<meta http-equiv="X-UA-Compatible" content="IE=EmulateIE7">
<title>会员中心-<?php echo $cfg_webname; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>" />
<script language="JavaScript" src="templets/images/jquery.js"></script>
<script language="JavaScript" src="templets/images/jquery.lazyload.js"></script>
<script language="JavaScript" src="templets/images/common.js"></script>
<script type="text/javascript" src="templets/js/feed.js"></script>
</head>
<body>
<?php include(DEDEMEMBER."/templets/head.htm"); ?>
<div class="main">
  <div class="navbar"> <span class="notice"><a href="#">位置</a></span>
    <ul class="position">
      <li><a href="/">网站首页</a></li>
      <li style="background-image: none; background-position: initial initial; background-repeat: initial initial;"><a href="/member/">会员中心</a></li>
    </ul>
  </div>
  <!--navbar end-->
  <div class="ucbox">
<?php include(DEDEMEMBER."/templets/left.htm"); ?>
    <!--ucleft end-->
    <div class="ucright">
      <div class="ucuser"> <span class="faceimg"><a href="<?php echo $cfg_cmsurl;?>/member/?uid=<?php echo $cfg_ml->M_LoginID; ?>" target="_blank"><img src="<?php echo $cfg_ml->fields['face']; ?>" width="78" height="78" alt="您的形象" original="templets/images/dfboy.png"></a></span>
        <div class="usermore">
          <h3 class="uname"><?php echo $cfg_ml->M_UserName?><cite>  </cite></h3>
          <span class="ucinfo"><a href="<?php echo $cfg_cmsurl;?>/member/?uid=<?php echo $cfg_ml->M_LoginID; ?>" target="_blank">个人主页</a> <a href="zl.php">修改资料</a> <a href="tx.php">我的头像</a></span>
          <ul class="uinfo">
            <li>注册日期：<?php echo date("Y-m-d",$cfg_ml->fields['jointime']); ?></li>
          </ul>
        </div>
        <ul class="otherinfo">
          <!--<li><cite id="citecolor"><a href="myfriend.php"><?php echo $minfos['friend']; ?></a></cite><br>
            <a href="myfriend.php">粉丝</a></li>
          <li><cite><?php echo $minfos['homecount']; ?></cite><br>
            人气</li>
          <li id="lastinfo"><cite><a href="mystow.php"><?php echo $minfos['stow']; ?></a></cite><br>
            <a href="mystow.php">收藏</a></li>
			-->
        </ul>
      </div>
      <!--ucuser end-->
      
      <div class="utool"> <span class="titlefont">常用功能</span>
        <ul class="usertool">
          <li><a href="article_add.php" class="tool1"></a>
            <p><a href="article_add.php">我要投稿</a></p>
          </li>
          <li><a href="content_list.php?channelid=1" class="tool2"></a>
            <p><a href="content_list.php?channelid=1">文章列表</a></p>
          </li>
          <li><a href="<?php echo $cfg_cmsurl;?>/member/?uid=<?php echo $cfg_ml->M_LoginID; ?>" class="tool5" target="_blank"></a>
            <p><a href="<?php echo $cfg_cmsurl;?>/member/?uid=<?php echo $cfg_ml->M_LoginID; ?>" target="_blank">个人主页</a></p>
          </li>
          <li><a href="/member/fxtg.php" class="tool4"></a>
            <p><a href="/member/fxtg.php">分享推广</a></p>
          </li>
          <li><a href="index_do.php?fmdo=login&dopost=exit#" class="tool3"></a>
            <p><a href="index_do.php?fmdo=login&dopost=exit#">安全注销</a></p>
          </li>
        </ul>
      </div>
      <div class="utitile"> <span class="titlefont2" style="line-height:48px;">最新稿件</span> </div>
      <dl class="ucmsg" id="ucmsg">
        <span>
        <div class="ucmsg" id="FeedText"></div>
        </span>
		<span>
		    <?php	
	$sql = "SELECT arc.*,mt.mtypename,addt.body,tp.typedir,tp.typename,tp.isdefault,tp.defaultname,tp.namerule,tp.namerule2,tp.ispart,tp.moresite,tp.siteurl,tp.sitepath
          FROM `#@__archives` arc 
          LEFT JOIN `#@__addonarticle` addt ON addt.aid=arc.id
          LEFT JOIN `#@__arctype` tp ON tp.id=arc.typeid 
          LEFT JOIN `#@__mtypes` mt ON mt.mtypeid=arc.mtype
          WHERE arc.mid='{$_vars['mid']}' $addqSql AND arc.ismake=1 AND arc.channel=1 ORDER BY arc.id DESC limit 1,8";
	//$row = $dsql->GetOne("SELECT  * from `#@__member_person` where mid='{$_vars['mid']}'");
    $dsql->SetQuery($sql);
    $dsql->Execute();
    while ($row = $dsql->GetArray())
        {
            $row['htmlurl'] = GetFileUrl($row['id'], $row['typeid'], $row['senddate'], $row['title'], $row['ismake'], $row['arcrank'], $row['namerule'], $row['typedir'], $row['money'], $row['filename'], $row['moresite'], $row['siteurl'], $row['sitepath']);
            $archives[] = $row;
			echo '<dd><cite><a href="'.$row['htmlurl'].'" target="_blank">'.'<img src="'.$row['litpic'].'"></a></cite><div class="umsg"><p>';
			echo '<a href="'.$row['htmlurl'].'" target="_blank">'.$row['title'].'</a><b>'.date("Y-m-d h:i",$row['pubdate']).'</b></p>';
			echo '<div class="umsgnr">'.$row['description'].'...</div></div></dd>';
        }

	?>
	</span>
      </dl>
	  
   <!--<a class="loadingmore" href="javascript:void(0)" onclick="gdt()"><cite id="stxt">加载更多相关内容</cite></a>--> </div>
    <!--urright end--> 


  </div>
  <!--ucbox end--> 
  
</div>
<!--main end-->
<?php include(DEDEMEMBER."/templets/foot.htm"); ?>
</body>
</html>