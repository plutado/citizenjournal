<div class="md-wrap">
	<input type="hidden" value="<?php print drupal_get_token('delete_tab');?>" id="delete_tab_token" />
	<a class="tab-link" id="add_tab" href="#"><span	class="tab-text">[Add new item]</span></a>
	<div id="md-tabs">
		<?php if (count($menu_tabs) > 0):?><!-- begin render tabs link -->
			<ul class="md-tabs-head clearfix">
			<?php foreach($menu_tabs as $key => $tab):?>
  			<li class="tab-item first clearfix">
    			<a class="tab-link" href="#tabs-<?php print $key+1;?>">
    			  <span class="tab-text"><?php print $tab->settings['general']['title'];?></span>
    		  </a>
    		  <span class="ui-icon ui-icon-close">Remove Tab</span>
  		  </li>
			<?php endforeach;?>
			</ul>
			<?php foreach ($menu_tabs as $key => $tab):?><!-- begin render tabs content -->
			  <div id="tabs-<?php print $key+1; ?>" class="clearfix">
			    <div class="settings">
  				  <a href="#" class="mnu-settings">[settings]</a>
  				  <input type="hidden" class="settings"	value='<?php print htmlentities(tab_setting_to_string($tab->settings, $menu, $tab->tid), ENT_QUOTES, "UTF-8")?>' />
			    </div><!-- /.settings -->
			    <?php if ($tab->settings['general']['is_dropdown_menu']): ?><!-- tab is dropdown menu -->
			    <div class="md-menudropdown clearfix" style="display: block;">
                  <div class="tree">
                  <?php if (count($tab->items)):?>
                    <?php print render_dropdown_tab($tab->items, $menu);?>
                  <?php else:?>
                    <ul></ul>
                  <?php endif;?>
                  </div>
                  <div class="dropdown-addnew">
                    <a class="mnu-addnewlink" href="#">[add new link]</a>
                  </div>
                </div>
            <div class="md-menuwrap clearfix fluid_mmcontainer_<?php print $tab->settings['layout']['col_grid']; ?>" style="display: none;">
  					  <?php foreach ($tab->settings['layout']['rows_setting'] as $row):?><!-- begin render rows in tabs -->
  					  <div class="md-row clearfix">
  					    <?php foreach ($row->cols as $col):?><!-- begin render columns -->
  					    <div class="md-col mmg_<?php print ($col->length*$tab->settings['layout']['col_grid'])/48;?>">
  					      <div class="inner ui-sortable"></div>
  					    </div><!-- /.md-col -->
  					    <?php endforeach;?><!-- end render columns -->
  					  </div><!-- /.md-row -->
  					  <?php endforeach;?><!-- end render rows in tabs -->
  					</div><!-- /.md-menuwrap -->
					<?php else: ?><!-- tab is megamenu -->
  					<div class="md-menudropdown clearfix">
              <div class="tree"></div>
              <div class="dropdown-addnew">
                <a class="mnu-addnewlink" href="#">[add new link]</a>
              </div>
            </div>
  				  <div class="md-menuwrap clearfix fluid_mmcontainer_<?php print $tab->settings['layout']['col_grid']; ?>">
  					  <?php foreach ($tab->settings['layout']['rows_setting'] as $row_id => $row):?><!-- begin render rows in tabs -->
  					  <div class="md-row clearfix">
  					    <?php foreach ($row->cols as $col_id => $col):?><!-- begin render columns -->
  					    <div class="md-col mmg_<?php print ($col->length*$tab->settings['layout']['col_grid'])/48;?>">
  					      <div class="inner ui-sortable">
  					        <?php if (isset($tab->items[$row_id][$col_id])):?>
                      <?php foreach ($tab->items[$row_id][$col_id] as $item): ?><!-- begin render items in column -->
  					            <?php print theme('megamenu_item_admin', array('item' => $item, 'icon_style' => ($item->type == 'img') ? $item->img_style : $menu->settings['design']['sub_dmi_img']));?>
  					        <?php endforeach; ?><!-- end render items in column -->
                    <?php endif;?>
  					      </div><!-- /.inner ui-sortable -->
  					    </div><!-- /.md-col -->
  					    <?php endforeach;?><!-- end render columns -->
  					  </div><!-- /.md-row -->
  					  <?php endforeach;?><!-- end render rows in tabs -->
  					</div><!-- /.md-menuwrap -->
					<?php endif;?>
			  </div><!-- /#tabs-key -->
			<?php endforeach;?><!-- end render tabs content -->
		<?php else: ?>
		  <ul class="md-tabs-head clearfix">
  			<li class="tab-item first clearfix" id="tab-home">
  			  <a class="tab-link"	href="#tabs-1"><span class="tab-text">Home</span></a>
  			  <span class="ui-icon ui-icon-close">Remove Tab</span>
			  </li>
		  </ul>
		  <div id="tabs-1" class="clearfix">
			  <div class="settings">
  				<a href="#" class="mnu-settings">[settings]</a>
  				<input type="hidden" class="settings" value='{"mnu_fly_type":false,"title_enabled":true,"mnu_title":"Home","mnu_path":"","icon_url":"","mnu_desc":"","mnu_class":"","smn_bgc":"","smn_bow":"","smn_bos":"solid","smn_boc":"","mnu_id":"<?php print $menu->mid;?>","tab_id":"0","mnu_layout":{"numCol":12,"isFullWidth":true,"subWidth":"","setting":[{"style":null,"cols":[{"style":null,"length":48}]},{"style":null,"cols":[{"style":null,"length":24},{"style":null,"length":24}]}]}}' />
  			</div>
  			<div class="md-menudropdown clearfix">
          <div class="tree"></div>
          <div class="dropdown-addnew">
            <a class="mnu-addnewlink" href="#">[add new link]</a>
          </div>
        </div>
  			<div class="md-menuwrap clearfix fluid_mmcontainer_12">
				  <div class="md-row clearfix">
					  <div class="md-col mmg_12">
					    <div class="inner ui-sortable"></div>
  					</div>
  				</div>
  				<div class="md-row clearfix">
  					<div class="md-col mmg_6">
  						<div class="inner"></div>
  					</div>
  					<div class="md-col mmg_6">
  						<div class="inner"></div>
  					</div>
					</div>
				</div>
			</div>
		<?php endif;?><!-- end render tabs links -->
	</div><!-- /#md-tabs -->

	<div id="blocklist" class="clearfix">
		<div class="md-listleft">
			<ul>
				<li class="ui-state-default ui-corner-top"><a href="#essentialitems">Essential Items</a></li>
				<?php foreach ($module_blocks_list as $module => $blocks):?>
				  <li class="ui-state-default ui-corner-top"><a href="#<?php print $module; ?>"><?php print $module; ?></a></li>
				<?php endforeach;?>
			</ul>
		</div><!-- /.md-listleft -->
		<div class="md-listcontent">
			<div id="essentialitems">
				<div data-title="Add a header" class="md-bl ei-header">
		        <input type="hidden" autocomplete="off" class="setting" />
						<a class="handle">+</a> <span class="ei-label">[header]</span>
						<span class="ei-text"><span></span> </span>
						<a href="#"	class="ei-remove"></a>
						<a href="#" class="ei-edit"></a>
					</div>
					<div data-title="Add a image" class="md-bl ei-image">
		        <input type="hidden" autocomplete="off" class="setting" />
						<a class="handle">+</a> <span class="ei-label">[image]</span>
						<a href="#" class="ei-remove"></a>
						<a href="#" class="ei-edit"></a>
					</div>
					<div data-title="Add a link" class="md-bl ei-link">
		        <input type="hidden" autocomplete="off" class="setting" />
						<a class="handle">+</a><span class="ei-label">[link]</span>
						<a href="#" class="ei-remove"></a>
						<a href="#" class="ei-edit"></a>
					</div>
					<div data-title="Add html" class="md-bl ei-html">
		        <input type="hidden" autocomplete="off" class="setting" />
						<a class="handle">+</a> <span class="ei-label">[html]</span>
						<a href="#" class="ei-remove"></a>
						<a href="#" class="ei-edit"></a>
					</div>
					<div data-title="Add a iframe" class="md-bl ei-iframe">
		        <input type="hidden" autocomplete="off" class="setting" />
						<a class="handle">+</a> <span class="ei-label">[iframe]</span>
						<a href="#" class="ei-remove"></a>
						<a href="#" class="ei-edit"></a>
					</div>
					<div data-title="Add a video" class="md-bl ei-video">
		        <input type="hidden" autocomplete="off" class="setting" />
						<a class="handle">+</a> <span class="ei-label">[video]</span>
						<a href="#" class="ei-remove"></a>
						<a href="#" class="ei-edit"></a>
					</div>
          <div data-title="Add a textblock" class="md-bl ei-textblock">
              <input type="hidden" autocomplete="off" class="setting" />
              <a class="handle">+</a> <span class="ei-label">[textblock]</span>
              <a href="#" class="ei-remove"></a>
              <a href="#" class="ei-edit"></a>
          </div>
          <div data-title="Add a seperator" class="md-bl ei-seperator">
              <input type="hidden" autocomplete="off" class="setting" value="type=seperator"/>
              <a class="handle">+</a> <span class="ei-label">[seperator]</span>
              <a href="#" class="ei-remove"></a>
          </div>
          <div data-title="Add a seperator with text" class="md-bl ei-seperatortext">
              <input type="hidden" autocomplete="off" class="setting" />
              <a class="handle">+</a> <span class="ei-label">[seperator with text]</span>
              <a href="#" class="ei-remove"></a>
              <a href="#" class="ei-edit"></a>
          </div>
          <div data-title="Add a twitter" class="md-bl ei-twitter">
              <input type="hidden" autocomplete="off" class="setting" />
              <a class="handle">+</a> <span class="ei-label">[twitter]</span>
              <a href="#" class="ei-remove"></a>
              <a href="#" class="ei-edit"></a>
          </div>
          <div data-title="Add a flickr" class="md-bl ei-flickr">
              <input type="hidden" autocomplete="off" class="setting" />
              <a class="handle">+</a> <span class="ei-label">[flickr]</span>
              <a href="#" class="ei-remove"></a>
              <a href="#" class="ei-edit"></a>
          </div>
          <div data-title="Add a gmap" class="md-bl ei-gmap">
              <input type="hidden" autocomplete="off" class="setting" />
              <a class="handle">+</a> <span class="ei-label">[gmap]</span>
              <a href="#" class="ei-remove"></a>
              <a href="#" class="ei-edit"></a>
          </div>
			</div><!-- essentialitems -->
			<?php foreach ($module_blocks_list as $module => $blocks): ?>
			  <div id="<?php print $module; ?>" class="connectedSortable clearfix">
			  <?php foreach ($blocks as $block): ?>
			    <div class="md-bl block-item ei-processed">
			      <input id="block-<?php print $block->bid;?>" class="setting" type="hidden" value="type=block&title=<?php print $block->info; ?>&block_id=<?php print $block->delta; ?>&block_module=<?php print $block->module; ?>" />
			      <a class="handle">+</a>
			      <span class="ei-label"><?php print $block->info; ?></span>
            <a class="bl-remove" href="#"></a>
			    </div>
			  <?php endforeach;?>
			  </div>
			<?php endforeach; ?>
		</div><!-- /.md-listcontent -->
	</div><!-- /#blocklist -->
	<div id="divlog"></div>
	<div id="itemWrap" class="mdmodal hide"></div>
</div><!-- /.md-wrap -->

<div id="dlg-flyout-item" title="Add a item"></div>
<div id="dlg-item" title=""></div>
<input id="savedcolor1" type="hidden" name="savedcolor1" value="ff9900,CC0000" />
