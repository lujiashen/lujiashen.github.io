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
                         <div class="hd"><h3><?php echo $GLOBALS['_vars']['uname']; ?>的留言本</h3></div>
                          <div class="comm_content">
 <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>                          
<div class="c_list clf">
<div class="c_hpic"> <a href="index.php?uid=<?php echo $fields['uname']; ?>&action=infos" title="<?php echo $fields['uname']; ?>" target="_blank">	
          <?php if($fields['face']==''){ 
	         $face=($fields['sex']=='女')? 'templets/images/dfgirl.png' : 'templets/images/dfboy.png';
            echo  '<img src="'.$face.'"/>';
		   }else{ 
	           echo  '<img src="'.$fields['face'].'" alt="'.$fields['uname'].'的头像" />';
	       } ?> </a></div>
<div class="c_fr">
<p class="c_meta"><a href='index.php?uid=<?php echo $fields['uname']; ?>'><?php echo $fields['uname']; ?></a><span class="c_time"><?php echo MyDate('Y-m-d H:i',$fields['dtime']);  
            	if($_vars['userid']==$cfg_ml->M_LoginID){
            		echo "<a class='plan' href='index.php?action=guestbookdel&aid=".$fields['aid']."&uid=".$_vars['userid']."&mid=".$fields['mid']."'>删除</a><a class='plan pmsms' target='_blank' href='/member/pm.php?dopost=send&amp;uid="."&uid=".$_vars['userid']."&mid=".$fields['mid']."'>回复</a>";
             	}
            ?>
              
</span>

</p>
<div class="c_nr"><?php echo Text2Html($fields['msg']); ?></div>
</div>
</div>

  <?php
}
}?>
         
<div id="pl_page"><div class="pagelistbox"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div></div><div class="cl"></div>
                        </div>
                      
				</div>
            	    
                <div class="inner">
                         <div class="hd"><h3>给我留言</h3></div>
                         <div class="quote_f">
  <form action="index.php" name="form1" method="post">
          <input type="hidden" name="action" value="guestbooksave" />
          <input type="hidden" name="uidnum" value="<?php echo $GLOBALS['_vars']['mid']; ?>" />
          <input type="hidden" name="uid" value="<?php echo $GLOBALS['_vars']['userid']; ?>" />
<textarea cols="60" name="msg" rows="5" id="msg" onfocus="iCc(this)">请在这里输入您要发表的评论信息!
理智评论,文明上网,共建和谐网络.
严禁广告、谩骂等不良信息.</textarea><br>
<label>验证码：</label>
          <input name="vdcode" type="text" class="text" id="vdcode" style="width:50px;text-transform:uppercase;" />
          <img src='../include/vdimgck.php' width='50' height='20' align="absmiddle" />
          
<input name="uname" type="hidden" value="1994"><input type="submit" id="pltj" value="提&nbsp;交" class="anbu">


</form>

 
        
                        </div>

                     
               </div>
            
            
            </div>
            
            
            
    </div>
<?php include $this->CompilerInclude("foot.htm");
 ?>