<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><div class="m_left">

        <div class="inner mt12 p0">
          <div class="hd">
            <h3>������Ϣ</h3>
          </div>
          <div class="bd">
            <ul class="detail-list">
              <li><i class="i-nc"></i>�ǳƣ�<span><?php echo $GLOBALS['_vars']['uname']; ?></span></li>
              <li><i class="i-dj"></i>�ȼ���<span><?php echo $GLOBALS['_vars']['membername']; ?></span></li>
              <li><i class="i-ip"></i>������<span><?php echo $GLOBALS['_vars']['homecount']; ?>��</span></li>
              <li class="born"><a href="index.php?uid=<?php echo urlencode($GLOBALS['_vars']['userid']); ?>&action=infos">�鿴��ϸ����</a></li>
            </ul>
          </div>
        </div>
        <div class="inner mt12 p0">
          <div class="hd">
            <h3>����ÿ�</h3>
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
          <li><a href="<?php echo $fields['url']; ?>" title="<?php echo $fields['uname']; ?>��ͷ��" target="_blank"><img src="<?php echo $fields['face']; ?>" alt="<?php echo $fields['uname']; ?>��ͷ��">
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