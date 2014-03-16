<div id="dlg-mnuitemsetting" title="Menu item data">
	<div class="dlg-inner">
  <form id="form-mnuitemsetting">
    <fieldset class="ui-helper-reset">
      <div id="mni-subtabs" class="md-subtabs">
        <div class="md-subtabs-head">
          <ul class="clearfix">
            <li class="subtab-item clearfix first"><a class="subtab-link" href="#mni-generalsettings">General settings</a></li>
            <li class="subtab-item clearfix last"><a class="subtab-link" href="#mni-layout">Layout</a></li>
          </ul>
        </div>
        <div id="mni-generalsettings" class="md-subtabcontent clearfix">
          <div class="form-left">
            <div class="form-item">
              <input type="checkbox" checked="checked" id="mnu_type" name="mnu_type" /><label for="mnu_type">Enable mega menu for this item</label>
            </div>
            <div class="form-item">
              <input type="checkbox" id="title_enabled" checked="checked" name="title_enabled" /><label for="title_enabled">Menu link title</label>
              <input	type="text" name="mnu_title" id="mnu_title"	class="form-text required" value="" />
              <input type="hidden" name="mnu_tab_id" id="mnu_tab_id" value="0" />
              <div class="description">The text to be used for this link in the menu. If disable, menu show icon only</div>
            </div>
            <div class="form-item">
              <label for="mnu_path">Path</label>
              <input type="text" name="mnu_path" id="mnu_path" class="form-text" value="" />
              <div class="description">The path for this menu link. This can be an internal Drupal path such as node/add or an external URL such as http://drupal.org. Enter &lt;front> to link to the front page.</div>
            </div>
          </div>
          <!-- /.form-left -->
          <div class="form-right">
            <div class="form-item form-desc">
              <label for="mnu_desc">Description </label>
              <textarea name="mnu_desc" id="mnu_desc"></textarea>
            </div>
            <div class="form-item file-upload form-menuicon">
              <div class="image-preview"></div>
              <a href="#" class="choose-image-link">Choose icon image</a>
              <input type="hidden" id="icon_url" value="" name="icon_url" />
            </div>
            <div class="form-item form-cssclasses">
              <label for="mnu_class">CSS Classes</label>
              <input type="text" name="mnu_class" id="mnu_class" class="form-text" value="" />
            </div>
          </div>
          <!-- /.form-right --> 
        </div>
        <!-- / #el-generalsettings -->
        <div id="mni-layout" class="md-subtabcontent clearfix">
          <div id="el-header">
            <div class="clearfix">
              <div class="el-template">
                <h4>Template:</h4>
                <div id="itemcolumn">
                  <div class="item itemcol1" value="[[24,24],[48]]"></div>
                  <div class="item itemcol2" value="[[48],[16,16,16]]"></div>
                  <div class="item itemcol3" value="[[12,12,12,12],[48]]"></div>
                  <div class="item itemcol4" value="[[48],[8,8,8,8,16]]"></div>
                  <div class="item itemcol5" value="[[8,8,8,8,8,8],[48]]"></div>
                </div>
              </div>
              <div class="el-columgrid">
                <h4>Column grid:</h4>
                <input type="radio" name="column_grid" id="column_mmg_12" checked="checked" value="12" />
                <label for="column_mmg_12">12</label>
                <input type="radio" name="column_grid" id="column_mmg_16" value="16" />
                <label for="column_mmg_16">16</label>
                <div class="el-fullwidth">
                  <input type="checkbox" name="submnu_full_width" id="submnu_full_width" />
                  <label for="submnu_full_width">Submenu full width</label>
                </div>
                <div id="mnu-sub-width">
                  <label for="mnu_subwid">Inset custom width</label>
                  <input id="mnu_subwid" class="form-text w60" type="text" value="" name="mnu_subwid">
                  <span>px</span>
                </div>
              </div>
            </div>
            <div class="el-buttons"><a href="#" class="md-button" id="layout_newrow">Add new row</a></div>
          </div>
          <!-- /#el-header -->
          <div id="el-gen" class="fluid_mmcontainer_12">
            <div class="el-row"> <a href="#" class="handle"></a>
              <div class="el-block mmg_12"> <a href="#" class="el-delete"></a> <a href="#" class="el-split"></a> <a href="#" class="el-wider"></a> <a href="#" class="el-shorten"></a> </div>
            </div>
            <div class="el-row"> <a href="#" class="handle"></a>
              <div class="el-block mmg_2"> <a href="#" class="el-delete"></a> <a href="#" class="el-split"></a> <a href="#" class="el-wider"></a> <a href="#" class="el-shorten"></a> </div>
              <div class="el-block mmg_10"> <a href="#" class="el-delete"></a> <a href="#" class="el-split"></a> <a href="#" class="el-wider"></a> <a href="#" class="el-shorten"></a> </div>
            </div>
          </div>
        </div><!-- / #el-layout -->        
      </div><!-- /#sub-tab -->
    </fieldset>
  </form>
</div>
</div>