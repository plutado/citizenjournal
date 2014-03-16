<?php if ($type == 'header'): ?>
  <h3 class="mm-header<?php print ($item->class != '') ? ' ' . $item->class : ''; ?>">
    <?php if ($item->h_icon != ''): ?>
      <?php print theme('image', array('path' => file_create_url($item->h_icon))); ?>
    <?php endif;?>
    <?php print $item->title?>
  </h3>
<?php elseif ($type == 'img' && $item->img_path != ''):?>
  <div>
     <?php print theme('image', array('path' => file_create_url($item->img_path), 'alt' => $item->img_alt, 'attributes' => array('class' => $item->class))); ?>
  </div>
<?php elseif ($type == 'a'):?>
<div>
  <?php if ($item->a_icon != ''): ?>
    <?php print theme('image', array('path' => file_create_url($item->a_icon))); ?>
  <?php endif;?>
  <?php print l($item->a_title, $item->a_path, array('attributes' => $item->attributes)); ?>
</div>
<?php elseif ($type == 'video'):?>
<div class="video-container">
  <iframe src="<?php print $item->video_link; ?>" frameborder="0" allowfullscreen<?php print $item->parameters?>></iframe>
</div>
<?php elseif ($type == 'html'):?>
  <div><?php print $item->html; ?></div>
<?php elseif ($type == 'iframe'):?>
<div>
  <iframe height="<?php print $item->iframe_height; ?>" src="<?php print urldecode($item->iframe_link); ?>"></iframe>
</div>
<?php elseif ($type == 'textblock'):?>
  <div<?php print ($item->class != '') ? ' class="' . $item->class . '"' : '';?>>
    <p class="<?php print $item->textblock_style;?>"><?php print $item->textblock_text;?></p>
  </div>
<?php elseif ($type == 'seperator'):?>
  <div class="md-separator"></div>
<?php elseif ($type == 'seperatortext'):?>
  <div class="md-separator-text md-separator-<?php print $item->seperator_align;?>"><div><?php print $item->seperator_text;?></div></div>
<?php elseif ($type == 'flickr'):?>
<div class="md_flickr<?php print ($item->class != '') ? ' ' . $item->class : '';?> clearfix">
    <script type="text/javascript" src="http://www.flickr.com/badge_code_v2.gne?count=<?php print $item->flickr_photos;?>&amp;display=<?php print $item->flickr_order;?>&amp;size=s&amp;layout=x&amp;source=<?php print $item->flickr_stream;?>&amp;user=<?php print $item->flickr_id;?>"></script>
</div>
<?php elseif ($type == 'twitter'):?>
  <div<?php print ($item->class != '') ? ' class="' . $item->class  . '"': '';?>>
  <div id="md-twitter-<?php print $item->twitter_name;?>"></div>
  <script type="text/javascript">
      <!--//--><![CDATA[//><!--
      (function($) {
          $(function() {
              $("#md-twitter-<?php print $item->twitter_name;?>").tweet({
                  username: "<?php print $item->twitter_name;?>",
                  count: <?php print $item->twitter_count;?>
              });
          });
      })(jQuery);
      //--><!]]>
  </script>
  </div>
<?php elseif ($type == 'gmap'):?>
<div class="md_gmap<?php print ($item->class != '') ? ' ' . $item->class : '';?>">
    <iframe width="100%" height="<?php print $item->gmap_height;?>" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="<?php print $item->url;?>"></iframe>
</div>
<?php endif;?>
