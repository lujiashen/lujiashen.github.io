<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><div class="m_left">

        <div class="inner mt12 p0">
          <div class="hd">
            <h3>个人信息</h3>
          </div>
          <div class="bd">
            <ul class="detail-list">
              <li><i class="i-nc"></i>昵称：<span><?php echo $GLOBALS['_vars']['uname']; ?></span></li>
              <li><i class="i-dj"></i>等级：<span><?php echo $GLOBALS['_vars']['membername']; ?></span></li>
              <li><i class="i-ip"></i>流量：<span><?php echo $GLOBALS['_vars']['homecount']; ?>次</span></li>
              <li class="born"><a href="index.php?uid=<?php echo urlencode($GLOBALS['_vars']['userid']); ?>&action=infos">查看详细资料</a></li>
            </ul>
          </div>
        </div>
        <div class="inner mt12 p0">
          <div class="hd">
            <h3>最近访客</h3>
          </div>
          <div class="bd">
            <ul class="avatar-list clf">
      <?php
$atts = array();
$atts['tagname'] = 'newvisitor';
$atts['row'] = '6';
$blockValue = MakePublicTag($atts,$this->refObj,$fields); 
if(is_array($blockValue) && count($blockValue) > 0){
foreach( $blockValue as $key=>$fields )
{
?>
          <li><a href="<?php echo $fields['url']; ?>" title="<?php echo $fields['uname']; ?>的头像" target="_blank"><img src="<?php echo $fields['face']; ?>" alt="<?php echo $fields['uname']; ?>的头像">
                <div class="a-name"><?php echo $fields['uname']; ?></div>
                </a></li>
         <?php
}
}
?>
                          </ul>
          </div>
        </div>
      </div>