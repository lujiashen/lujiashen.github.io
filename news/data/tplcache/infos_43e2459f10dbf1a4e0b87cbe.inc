<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
 include $this->CompilerInclude("head.htm");
 ?>
<div class="layout-body">
<div class="w960  clf"> <?php include $this->CompilerInclude("m_left.htm");
 ?>
  <div class="m_main">
    <div class="inner"> 
     <?php 
            	if($_vars['userid']==$cfg_ml->M_LoginID){
            		echo " <a class='ckxx' href='/member/zl.php'>设置</a> ";
             	}
            ?>
            
            
      <div class="hd">
        <h3>基本资料</h3>
      </div>
      <div class="infos"> 昵称：<?php echo $GLOBALS['_vars']['uname']; ?><br>
        性别：<?php echo $row['sex']; ?><br>
        出生日期：<?php echo $row['birthday']; ?><br>
      </div>
    </div>
   </div>
</div>
<?php include $this->CompilerInclude("foot.htm");
 ?>