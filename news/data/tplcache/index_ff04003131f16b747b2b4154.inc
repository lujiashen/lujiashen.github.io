<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
 include $this->CompilerInclude("head.htm");
 ?>
  <div class="layout-body">
    <div class="w960  clf">
<?php include $this->CompilerInclude("m_left.htm");
 ?>
      <div class="m_main">
        <div class="inner">
          <div class="hd">
            <h3>空间公告</h3>
          </div>
          <div class="i_xx clf spacenews"> <?php echo $GLOBALS['_vars']['spacenews']; ?> </div>
        </div>
        <?php
$atts = array();
$atts['tagname'] = 'spacenewart';
$atts['row'] = '10';
$atts['titlelen'] = '100';
$blockValue = MakePublicTag($atts,$this->refObj,$fields); 
if(is_array($blockValue) && count($blockValue) > 0){
foreach( $blockValue as $key=>$fields )
{
?>
        <div class="inner"> <a class="ckxx" href="<?php echo $fields['arcurl']; ?>" target="_blank">查看详细</a>
          <div class="hd">
            <h3><a href="<?php echo $fields['arcurl']; ?>"><?php echo $fields['title']; ?></a></h3>
          </div>
          <div class="i_info">栏目:<a href="<?php echo $fields['typeurl']; ?>" class="lm" target="_blank"><?php echo $fields['typename']; ?></a><em></em>时间:<?php echo MyDate('Y-m-d h:i',$fields['pubdate']); ?><em></em>浏览:<?php echo $fields['click']; ?></div>
          <div class="i_xx clf"> <a href="<?php echo $fields['arcurl']; ?>" target="_blank"><img src="<?php echo $fields['picname']; ?>" width="240" height="150" class="litpic" alt="<?php echo $fields['title']; ?>"></a> <?php echo $fields['description']; ?> </div>
        </div>
        <?php
}
}
 if($autoi==1){?>
        asdasda
        <?php }?>
        <div class="inner more"><a href="index.php?uid=<?php echo $GLOBALS['_vars']['userid_e']; ?>&action=archives">更多内容&gt;&gt;</a></div>
      </div>
    </div>
<?php include $this->CompilerInclude("foot.htm");
 ?>