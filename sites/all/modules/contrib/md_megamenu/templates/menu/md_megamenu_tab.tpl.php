<li class="<?php print $tab_classes; ?>">
  <?php print $tab->content; ?>
  <div class="<?php print $row_classes?>"<?php print $row_extends?>>
    <?php foreach ($rows as $row): ?>
      <div class="mm-sub clearfix"<?php print ' ' . $row->style;?>>
        <?php foreach ($row->cols as $col): ?>
          <div class="<?php print $col->classes?>"<?php print ' ' . $col->div_col;?>>
            <div class="inner"<?php print $col->inner;?>>
            <?php print theme('megamenu_col_content', array('items' => $col->items))?>
            </div>
          </div>
        <?php endforeach;?>
      </div>
    <?php endforeach;?>
  </div>
</li>