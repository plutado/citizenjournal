<?php if ($item): ?>
  <?php $type = $item->type;?>
  <?php if ($type == "block"):?>
    <div id="md-bl<?php print $item->block_id;?>" class="md-bl block-item ei-processed" style="display: block;">
      <input id="block-<?php print $item->block_id;?>" type="hidden" class="setting" value="type=block&title=<?php print $item->title;?>&block_id=<?php print $item->block_id;?>&block_module=<?php print $item->block_module;?>" />
      <a class="handle">+</a>
      <span class="ei-label"><?php print $item->title;?></span>
      <a class="bl-remove" href="#"></a>
    </div>
  <?php elseif ($type == "header"):?>
    <div class="md-bl ei-header ui-draggable ei-processed" data-title="Add a header" style="display: block;">
      <input class="setting" type="hidden" autocomplete="off" value="type=header&title=<?php print $item->title; ?>&class=<?php print $item->class; ?>&h_icon=<?php print $item->h_icon; ?>">
      <a class="handle">+</a>
      <span class="ei-label">[header]</span>
      <span class="ei-text">
      <span><?php print urldecode($item->title); ?></span>
      </span>
      <a class="ei-remove" href="#"></a>
      <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'a'):?>
    <div class="md-bl ei-link ui-draggable ei-processed" data-title="Add a link" style="display: block;">
      <input class="setting" type="hidden" autocomplete="off" value="type=a&a_title=<?php print urldecode($item->a_title); ?>&a_path=<?php print $item->a_path; ?>&a_target=<?php print $item->a_target; ?>&a_icon=<?php print $item->a_icon; ?>&class=<?php print $item->class; ?>">
      <a class="handle">+</a>
      <span class="ei-label">[link]</span>
      <a class="ei-remove" href="#"></a>
      <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'img'):?>
    <div class="md-bl ei-image ui-draggable ei-processed" data-title="Add a image" style="display: block;">
      <input class="setting" type="hidden" autocomplete="off" value="type=img&img_path=<?php print $item->img_path; ?>&img_alt=<?php print $item->img_alt; ?>&class=<?php print $item->class; ?>&img_style=<?php print $item->img_style; ?>">
      <a class="handle">+</a>
      <span class="ei-label">[image]</span>
      <a class="ei-remove" href="#"></a>
      <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'html'): ?>
    <div class="md-bl ei-html ui-draggable ei-processed" data-title="Add html" style="display: block;">
      <input class="setting" type="hidden" autocomplete="off" value="type=html&html=<?php print htmlentities($item->html, ENT_QUOTES, "UTF-8"); ?>">
      <a class="handle">+</a>
      <span class="ei-label">[html]</span>
      <a class="ei-remove" href="#"></a>
      <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'iframe'): ?>
    <div class="md-bl ei-iframe ui-draggable ei-processed" data-title="Add a iframe" style="display: block;">
      <input class="setting" type="hidden" autocomplete="off" value="type=iframe&iframe_link=<?php print $item->iframe_link; ?>&iframe_height=<?php print $item->iframe_height; ?>">
      <a class="handle">+</a>
      <span class="ei-label">[iframe]</span>
      <a class="ei-remove" href="#"></a>
      <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'video'): ?>
    <div class="md-bl ei-video ui-draggable ei-processed" data-title="Add a video" style="display: block;">
      <input class="setting" type="hidden" autocomplete="off" value="type=video&video_link=<?php print $item->video_link; ?>">
      <a class="handle">+</a>
      <span class="ei-label">[video]</span>
      <a class="ei-remove" href="#"></a>
      <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'textblock'): ?>
    <div class="md-bl ei-textblock ui-draggable ei-processed" data-title="Add new text" style="display: block;">
        <input class="setting" type="hidden" autocomplete="off" value="type=textblock&textblock_text=<?php print $item->textblock_text;?>&textblock_style=<?php print $item->textblock_style;?>&class=<?php print $item->class;?>">
        <a class="handle">+</a>
        <span class="ei-label">[text block]</span>
        <a class="ei-remove" href="#"></a>
        <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'seperator'): ?>
    <div class="md-bl ei-seperator ui-draggable ei-processed" data-title="Add seperator" style="display: block;">
        <input class="setting" type="hidden" autocomplete="off" value="type=seperator">
        <a class="handle">+</a>
        <span class="ei-label">[seperator]</span>
        <a class="ei-remove" href="#"></a>
    </div>
  <?php elseif ($type == 'seperatortext'): ?>
    <div class="md-bl ei-seperatortext ui-draggable ei-processed" data-title="Add seperator with text" style="display: block;">
        <input class="setting" type="hidden" autocomplete="off" value="type=seperatortext&seperator_text=<?php print $item->seperator_text;?>&seperator_align=<?php print $item->seperator_align;?>&class=<?php print $item->class;?>">
        <a class="handle">+</a>
        <span class="ei-label">[seperator with text]</span>
        <a class="ei-remove" href="#"></a>
        <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'twitter'): ?>
    <div class="md-bl ei-twitter ui-draggable ei-processed" data-title="Add twitter" style="display: block;">
        <input class="setting" type="hidden" autocomplete="off" value="type=twitter&twitter_name=<?php print $item->twitter_name;?>&twitter_count=<?php print $item->twitter_count;?>&class=<?php print $item->class;?>">
        <a class="handle">+</a>
        <span class="ei-label">[twitter]</span>
        <a class="ei-remove" href="#"></a>
        <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'flickr'): ?>
    <div class="md-bl ei-flickr ui-draggable ei-processed" data-title="Add flickr" style="display: block;">
        <input class="setting" type="hidden" autocomplete="off" value="type=flickr&flickr_id=<?php print $item->flickr_id;?>&flickr_photos=<?php print $item->flickr_photos;?>&flickr_stream=<?php print $item->flickr_stream;?>&flickr_order=<?php print $item->flickr_order;?>&class=<?php print $item->class;?>">
        <a class="handle">+</a>
        <span class="ei-label">[flickr]</span>
        <a class="ei-remove" href="#"></a>
        <a class="ei-edit" href="#"></a>
    </div>
  <?php elseif ($type == 'gmap'): ?>
    <div class="md-bl ei-gmap ui-draggable ei-processed" data-title="Add gmap" style="display: block;">
        <input class="setting" type="hidden" autocomplete="off" value="type=gmap&gmap_link=<?php print $item->gmap_link;?>&gmap_height=<?php print $item->gmap_height;?>&gmap_type=<?php print $item->gmap_type;?>&gmap_zoom=<?php print $item->gmap_zoom;?>&class=<?php print $item->class;?>">
        <a class="handle">+</a>
        <span class="ei-label">[gmap]</span>
        <a class="ei-remove" href="#"></a>
        <a class="ei-edit" href="#"></a>
    </div>
  <?php endif;?>
<?php endif;?>
