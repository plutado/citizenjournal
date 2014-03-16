<?php if(isset($parameters["type"])): $type = $parameters["type"]?>
	<?php if($type == "header"): // ELEMENT: Header ?>
    	<div class="dlg-inner">
  			<form>
            <fieldset class="ui-helper-reset">
            	<input type="hidden" name="type"  value="header" />
              <div class="form-item">
              	<label for="title">Header title</label>
              	<input type="text" name="title" id="title" class="form-text" value="<?php print isset($parameters["title"]) ? $parameters["title"] : ''?>" />
              </div>
              <div class="form-item file-upload form-menuitemicon">
                  <div class="image-preview">
                  <?php if (isset($parameters["h_icon"])):?>
                    <img src="<?php print get_icon_url($parameters["h_icon"])?>" />
                  <?php endif;?>
                  </div>
                  <a href="#" class="choose-image-link">Choose icon image</a>
                  <input name="h_icon" type="hidden" class="form-text" value="<?php print isset($parameters["h_icon"]) ? $parameters["h_icon"] : ''?>" />
              </div>
              <div class="form-item form-cssclasses">
              	<label for="header_class">CSS Classes</label>
              	<input type="text" name="class" id="header_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
              </div>
            </fieldset>
        </form>
      </div>
    <?php elseif($type == "img"):?>
      <div class="dlg-inner">
        <form>
          <fieldset class="ui-helper-reset">
            <input type="hidden" name="type"  value="img" />
            <div class="image-preview">
              <?php if (isset($parameters["img_path"])):?>
                <img src="<?php print get_icon_url($parameters["img_path"])?>" />
              <?php endif;?>
            </div>
            <a href="#" class="choose-image-link">Choose icon image</a>
            <input type="hidden" name="img_path"  value="<?php print isset($parameters["img_path"]) ? $parameters["img_path"] : ''?>" />
            <div class="form-item">
              <?php $img_style = isset($parameters["img_style"]) ? $parameters["img_style"] : ''?>
              <select name="img_style">
                <option value=""<?php print ($img_style == '') ? ' selected="selected"' : ""?>>None (Original image)</option>
                <?php foreach (image_style_options(FALSE) as $key => $val): ?>
                  <option value="<?php print $key;?>"<?php print ($img_style == $key) ? ' selected="selected"' : ""?>><?php print $val;?></option>
                <?php endforeach;?>
              </select>
            </div>

            <div class="form-item">
              <label for="img_alt">Alt text</label>
            	<input type="text" name="img_alt" id="img_alt" class="form-text" value="<?php print isset($parameters["img_alt"]) ? $parameters["img_alt"] : ''?>" />
            </div>
            <div class="form-item form-cssclasses">
            	<label for="img_class">CSS Classes</label>
            	<input type="text" name="class" id="img_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
            </div>
          </fieldset>
        </form>
      </div>
  	<?php elseif($type == "a"):?>
  		<div class="dlg-inner">
		 <form>
            <fieldset class="ui-helper-reset">
            	<input type="hidden" name="type"  value="a" />
              <div class="form-item">
                <label for="a_title">Link title</label>
              	<input type="text" name="a_title" id="a_title" class="form-text" value="<?php print isset($parameters["a_title"]) ? $parameters["a_title"] : ''?>" />
              </div>
              <div class="form-item">
                <label for="a_path">Link path</label>
              	<input type="text" name="a_path" id="a_path" class="form-text" value="<?php print isset($parameters["a_path"]) ? $parameters["a_path"] : ''?>" />
              </div>
              <div class="form-item">
              	<label for="a_target">Target</label>
              	<?php $target = isset($parameters["a_target"]) ? $parameters["a_target"] : 'none'?>
              	<select name="a_target">
              	    <option value="none"<?php print ($target == "none") ? ' selected="selected"' : ""?> >none</option>
                	<option value="_blank"<?php print ($target == "_blank") ? ' selected="selected"' : ""?> >_blank</option>
                	<option value="_new"<?php print ($target == "_new") ? ' selected="selected"' : ""?> >_new</option>
                	<option value="_parent"<?php print ($target == "_parent") ? ' selected="selected"' : ""?>>_parent</option>
                	<option value="_self"<?php print ($target == "_self") ? ' selected="selected"' : ""?>>_self</option>
                	<option value="_top"<?php print ($target == "_top") ? ' selected="selected"' : ""?>>_top</option>
                </select>
              </div>
              <div class="form-item file-upload form-menuitemicon">
                <div class="image-preview">
                  <?php if (isset($parameters["a_icon"])):?>
                    <img src="<?php print get_icon_url($parameters["a_icon"])?>" />
                  <?php endif;?>
                </div>
                <a href="#" class="choose-image-link">Choose icon image</a>
                <input type="hidden" name="a_icon" class="form-text" value="<?php print isset($parameters["a_icon"]) ? $parameters["a_icon"] : ''?>" />
              </div>
              <div class="form-item form-cssclasses">
				        <label for="img_class">CSS Classes</label>
              	<input type="text" name="class" id="img_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
              </div>
            </fieldset>
          </form>
		</div>
	<?php elseif($type == "html"):?>
  	<div class="dlg-inner dlg-html">
  	  <form>
        <fieldset class="ui-helper-reset">
        	<input type="hidden" name="type"  value="html" />
        	<textarea name="html" id="cleditor" class="form-text"><?php print isset($parameters["html"]) ? $parameters["html"] : ''?></textarea>
        </fieldset>
      </form>
    </div>
    <script type="text/javascript">
      (function($) {
        $(document).ready(function() {
        		if($("#cleditor").size() > 0) {
        			$("#cleditor").cleditor({
        					width: 800,
        					height: 450,
        					controls:     // controls to add to the toolbar
        								 "megastyle | bold italic underline strikethrough | " +
        								 "bullets numbering | image table link unlink  | color highlight removeformat | alignleft center alignright justify | " +
        								 "rule | undo redo | source",
									docCSSFile: Drupal.settings.cleditor_docfile
        				})[0].focus();
        		}
        });
      })(jQuery);
    </script>
	<?php elseif($type == "iframe"):?>
		<div class="dlg-inner">
		 	<form>
              <fieldset class="ui-helper-reset">
              	<input type="hidden" name="type"  value="iframe" />
                <div class="form-item">
                	<label for="iframe_link">iframe link</label>
                	<input type="text" name="iframe_link" id="iframe_link" class="form-text" value="<?php print isset($parameters["iframe_link"]) ? $parameters["iframe_link"] : ''?>" />
                </div>
                <div class="form-item">
                  <label for="iframe_height">iframe height</label>
                	<input type="text" name="iframe_height" id="iframe_height" class="form-text" value="<?php print isset($parameters["iframe_height"]) ? $parameters["iframe_height"] : '100'?>" />
                </div>
              </fieldset>
          </form>
		</div>
	<?php elseif($type == "video"):?>
		<div class="dlg-inner">
		 <form>
            <fieldset class="ui-helper-reset">
            	<input type="hidden" name="type" value="video" />
              <div class="form-item">
              	<label for="video_link">video link</label>
              	<input type="text" name="video_link" id="video_link" class="form-text" value="<?php print isset($parameters["video_link"]) ? $parameters["video_link"] : ''?>" />
              </div>
            </fieldset>
          </form>
		</div>
  <?php elseif($type == "textblock"):?>
		<div class="dlg-inner">
        <form>
            <fieldset class="ui-helper-reset">
                <input type="hidden" name="type" value="textblock" />
                <div class="form-item">
                    <label for="textblock_text">Text</label>
                    <textarea name="textblock_text" id="textblock_text" class="form-text"><?php print isset($parameters["textblock_text"]) ? $parameters["textblock_text"] : ''?></textarea>
                </div>
                <div class="form-item">
                    <label for="textblock_style">Style</label>
                  <?php $textblock_style = isset($parameters["textblock_style"]) ? $parameters["textblock_style"] : 'none'?>
                    <select name="textblock_style">
                        <option value="message"<?php print ($textblock_style == "message") ? ' selected="selected"' : ""?> >Message</option>
                        <option value="message-success"<?php print ($textblock_style == "message-success") ? ' selected="selected"' : ""?> >Message Success</option>
                        <option value="message-error"<?php print ($textblock_style == "message-error") ? ' selected="selected"' : ""?> >Message Error</option>
                        <option value="message-info"<?php print ($textblock_style == "message-info") ? ' selected="selected"' : ""?> >Message Info</option>
                        <option value="icon-warning"<?php print ($textblock_style == "icon-warning") ? ' selected="selected"' : ""?> >Icon Warning</option>
                        <option value="icon-lock"<?php print ($textblock_style == "icon-lock") ? ' selected="selected"' : ""?> >Icon Lock</option>
                        <option value="icon-info"<?php print ($textblock_style == "icon-info") ? ' selected="selected"' : ""?> >Icon Info</option>
                        <option value="icon-question"<?php print ($textblock_style == "icon-question") ? ' selected="selected"' : ""?> >Icon Question</option>
                        <option value="icon-tips"<?php print ($textblock_style == "icon-tips") ? ' selected="selected"' : ""?> >Icon Tips</option>
                        <option value="icon-rss"<?php print ($textblock_style == "icon-rss") ? ' selected="selected"' : ""?> >Icon RSS</option>
                        <option value="icon-doc"<?php print ($textblock_style == "icon-doc") ? ' selected="selected"' : ""?> >Icon Doc</option>
                        <option value="icon-note"<?php print ($textblock_style == "icon-note") ? ' selected="selected"' : ""?> >Icon Note</option>
                        <option value="icon-star"<?php print ($textblock_style == "icon-star") ? ' selected="selected"' : ""?> >Icon Star</option>
                    </select>
                </div>
                <div class="form-item form-cssclasses">
                    <label for="css_class">CSS Classes</label>
                    <input type="text" name="class" id="css_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
                </div>
            </fieldset>
        </form>
    </div>
  <?php elseif($type == "seperatortext"):?>
    <div class="dlg-inner">
        <form>
            <fieldset class="ui-helper-reset">
                <input type="hidden" name="type" value="seperatortext" />
                <div class="form-item">
                    <label for="seperator_text">Seperator text</label>
                    <input type="text" name="seperator_text" id="seperator_text" class="form-text" value="<?php print isset($parameters["seperator_text"]) ? $parameters["seperator_text"] : ''?>" />
                </div>
                <div class="form-item">
                    <label for="seperator_align">Style</label>
                  <?php $seperator_align = isset($parameters["seperator_align"]) ? $parameters["seperator_align"] : 'none'?>
                    <select name="seperator_align">
                        <option value="aligncenter"<?php print ($seperator_align == "aligncenter") ? ' selected="selected"' : ""?> >Align Center</option>
                        <option value="alignleft"<?php print ($seperator_align == "alignleft") ? ' selected="selected"' : ""?> >Align Left</option>
                        <option value="alignright"<?php print ($seperator_align == "alignright") ? ' selected="selected"' : ""?> >Align Right</option>
                    </select>
                </div>
                <div class="form-item form-cssclasses">
                    <label for="css_class">CSS Classes</label>
                    <input type="text" name="class" id="css_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
                </div>
            </fieldset>
        </form>
    </div>
  <?php elseif($type == "twitter"):?>
    <div class="dlg-inner">
        <form>
            <fieldset class="ui-helper-reset">
                <input type="hidden" name="type" value="twitter" />
                <div class="form-item">
                    <label for="twitter_name">Twitter name</label>
                    <input type="text" name="twitter_name" id="twitter_name" class="form-text" value="<?php print isset($parameters["twitter_name"]) ? $parameters["twitter_name"] : ''?>" />
                </div>
                <div class="form-item">
                    <label for="twitter_count">Tweet count</label>
                    <input type="text" name="twitter_count" id="twitter_count" class="form-text" value="<?php print isset($parameters["twitter_count"]) ? $parameters["twitter_count"] : ''?>" />
                </div>
                <div class="form-item form-cssclasses">
                    <label for="css_class">CSS Classes</label>
                    <input type="text" name="class" id="css_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
                </div>
            </fieldset>
        </form>
    </div>
  <?php elseif($type == "flickr"):?>
    <div class="dlg-inner">
        <form>
            <fieldset class="ui-helper-reset">
                <input type="hidden" name="type" value="flickr" />
                <div class="form-item">
                    <label for="flickr_id">Flickr ID</label>
                    <input type="text" name="flickr_id" id="flickr_id" class="form-text" value="<?php print isset($parameters["flickr_id"]) ? $parameters["flickr_id"] : ''?>" />
                    <div class="description">To find your flickID visit <a href="http://idgettr.com/" target="_blank">idGettr</a></div>
                </div>
                <div class="form-item">
                    <label for="flickr_photos">Number of photos</label>
                    <input type="text" name="flickr_photos" id="flickr_photos" class="form-text" value="<?php print isset($parameters["flickr_photos"]) ? $parameters["flickr_photos"] : ''?>" />
                </div>
                <div class="form-item">
                    <label for="flickr_stream">Photo stream type</label>
                  <?php $flickr_stream = isset($parameters["flickr_stream"]) ? $parameters["flickr_stream"] : 'none'?>
                    <select name="flickr_stream" id="flickr_stream">
                        <option value="user"<?php print ($flickr_stream == "user") ? ' selected="selected"' : ""?> >User</option>
                        <option value="group"<?php print ($flickr_stream == "group") ? ' selected="selected"' : ""?> >Group</option>
                    </select>
                </div>
                <div class="form-item">
                    <label for="flickr_order">Photo order</label>
                  <?php $flickr_order = isset($parameters["flickr_order"]) ? $parameters["flickr_order"] : 'none'?>
                    <select name="flickr_order" id="flickr_order">
                        <option value="latest"<?php print ($flickr_order == "latest") ? ' selected="selected"' : ""?> >Latest</option>
                        <option value="group"<?php print ($flickr_order == "group") ? ' selected="selected"' : ""?> >Random</option>
                    </select>
                </div>
                <div class="form-item form-cssclasses">
                    <label for="css_class">CSS Classes</label>
                    <input type="text" name="class" id="css_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
                </div>
            </fieldset>
        </form>
    </div>
  <?php elseif($type == "gmap"):?>
    <div class="dlg-inner">
        <form>
            <fieldset class="ui-helper-reset">
                <input type="hidden" name="type" value="gmap" />
                <div class="form-item">
                    <label for="gmap_link">Google map link</label>
                    <input type="text" name="gmap_link" id="gmap_link" class="form-text" value="<?php print isset($parameters["gmap_link"]) ? $parameters["gmap_link"] : ''?>" />
                    <div class="description">Visit <a href="http://maps.google.com/" target="_blank">Google maps</a> find your address and then click "Link" button to obtain your map link.</div>
                </div>
                <div class="form-item">
                    <label for="gmap_height">Map height</label>
                    <input type="text" name="gmap_height" id="gmap_height" class="form-text" value="<?php print isset($parameters["gmap_height"]) ? $parameters["gmap_height"] : ''?>" />
                </div>
                <div class="form-item">
                    <label for="gmap_type">Map type</label>
                  <?php $gmap_type = isset($parameters["gmap_type"]) ? $parameters["gmap_type"] : 'none'?>
                    <select name="gmap_type" id="gmap_type">
                        <option value="m"<?php print ($gmap_type == "m") ? ' selected="selected"' : ""?> >Map</option>
                        <option value="k"<?php print ($gmap_type == "k") ? ' selected="selected"' : ""?> >Satellite</option>
                        <option value="p"<?php print ($gmap_type == "p") ? ' selected="selected"' : ""?> >Map + Terrain</option>
                    </select>
                </div>
                <div class="form-item">
                    <label for="gmap_zoom">Map zoom</label>
                  <?php $gmap_zoom = isset($parameters["gmap_zoom"]) ? $parameters["gmap_zoom"] : 14;?>
                    <select name="gmap_zoom" id="gmap_zoom">
                        <?php for ($i = 1; $i < 21; $i++): ?>
                        <option value="<?php print $i;?>"<?php print ($gmap_zoom == $i) ? ' selected="selected"' : ""?> ><?php print $i;?></option>
                        <?php endfor;?>
                    </select>
                </div>
                <div class="form-item form-cssclasses">
                    <label for="css_class">CSS Classes</label>
                    <input type="text" name="class" id="css_class" class="form-text" value="<?php print isset($parameters["class"]) ? $parameters["class"] : ''?>" />
                </div>
            </fieldset>
        </form>
    </div>
	<?php endif;?>
<?php endif;?>
