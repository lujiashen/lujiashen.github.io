    <?php
        $add_channel_menu = array();
        //���Ϊ�οͷ��ʣ����������˵�
        if(!empty($cfg_ml->M_ID))
        {
            $channelInfos = array();
            $dsql->Execute('addmod',"SELECT id,nid,typename,useraddcon,usermancon,issend,issystem,usertype,isshow FROM `#@__channeltype` ");	
            while($menurow = $dsql->GetArray('addmod'))
            {
                $channelInfos[$menurow['nid']] = $menurow;
                //���õ�ģ��
                if($menurow['isshow']==0)
                {
                    continue;
                }
                //�������
                if($menurow['issend']!=1 || $menurow['issystem']==1 
                || ( !preg_match("#".$cfg_ml->M_MbType."#", $menurow['usertype']) && trim($menurow['usertype'])!='' ) )
                {
                    continue;
                }
                $menurow['ddcon'] = empty($menurow['useraddcon']) ? 'archives_add.php' : $menurow['useraddcon'];
                $menurow['list'] = empty($menurow['usermancon']) ? 'content_list.php' : $menurow['usermancon'];
                $add_channel_menu[] = $menurow;
            }
            unset($menurow);
		?>
 
      	<!-- �������Ĳ˵�-->
      	<?php
		      	if($menutype == 'mydede')

      	{
      	?>
   
        <?php
        //�Ƿ���������Ͷ��
        if($channelInfos['article']['issend']==1 && $channelInfos['article']['isshow']==1)
        {
        ?>
                  <dd><a href="article_add" title="��ҪͶ��">��ҪͶ��</a></dd>
				  <dd><a href="content_list.php?channelid=1" title="�ѷ���������">���¹���</a></dd>
        <?php
      	}
        ?>
 
         <?php
      }
      ?>
      	<!-- �ҵ�֯�β˵�-->
      	<?php
      	if($menutype == 'content')
      	{
      	?>


<?php
        if($cfg_feedback_forbid=='N')
        {
          //<dd class="icon feedback"><a href='../member/myfeedback.php'>�ҵ�����</a></dd>
        }
        $dsql->Execute('nn','Select indexname,indexurl From `#@__sys_module` where ismember=1 ');
        while($nnarr = $dsql->GetArray('nn'))
        {
        	@preg_match("/\/(.+?)\//is", $nnarr['indexurl'],$matches);
        	$nnarr['class'] = isset($matches[1]) ? $matches[1] : 'channel';
        	$nnarr['indexurl'] = str_replace("**","=",$nnarr['indexurl']);
        ?>
       
        <?php
        }
        ?>
         <?php
      }
      ?>
      	<!-- ϵͳ���ò˵�-->
      	<?php
      	if($menutype == 'config')
      	{
      	?>
         
        <?php
      }
      ?>
       <?php
    }
    ?>
   
