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
            		echo " <a class='ckxx' href='/member/zl.php'>����</a> ";
             	}
            ?>
            
            
      <div class="hd">
        <h3>��������</h3>
      </div>
      <div class="infos"> �ǳƣ�<?php echo $GLOBALS['_vars']['uname']; ?><br>
        �Ա�<?php echo $row['sex']; ?><br>
        �������ڣ�<?php echo $row['birthday']; ?><br>
      </div>
    </div>
   </div>
</div>
<?php include $this->CompilerInclude("foot.htm");
 ?>