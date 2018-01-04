    <?php
        $add_channel_menu = array();
        //如果为游客访问，不启用左侧菜单
        if(!empty($cfg_ml->M_ID))
        {
            $channelInfos = array();
            $dsql->Execute('addmod',"SELECT id,nid,typename,useraddcon,usermancon,issend,issystem,usertype,isshow FROM `#@__channeltype` ");	
            while($menurow = $dsql->GetArray('addmod'))
            {
                $channelInfos[$menurow['nid']] = $menurow;
                //禁用的模型
                if($menurow['isshow']==0)
                {
                    continue;
                }
                //其它情况
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
 
      	<!-- 内容中心菜单-->
      	<?php
		      	if($menutype == 'mydede')

      	{
      	?>
   
        <?php
        //是否启用文章投稿
        if($channelInfos['article']['issend']==1 && $channelInfos['article']['isshow']==1)
        {
        ?>
                  <dd><a href="article_add" title="我要投稿">我要投稿</a></dd>
				  <dd><a href="content_list.php?channelid=1" title="已发布的文章">文章管理</a></dd>
        <?php
      	}
        ?>
 
         <?php
      }
      ?>
      	<!-- 我的织梦菜单-->
      	<?php
      	if($menutype == 'content')
      	{
      	?>


<?php
        if($cfg_feedback_forbid=='N')
        {
          //<dd class="icon feedback"><a href='../member/myfeedback.php'>我的评论</a></dd>
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
      	<!-- 系统设置菜单-->
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
   
