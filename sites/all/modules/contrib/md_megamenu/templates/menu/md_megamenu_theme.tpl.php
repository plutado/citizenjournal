<div id="megamenu-<?php print $mid;?>" class="<?php print $menu_classes; ?>">
  <ul id="mdmegamenu-<?php print $mid;?>" class="megamenu clearfix">
    <?php foreach ($menu_tabs as $key => $tab):?>
      <?php if ($tab->settings['general']['is_dropdown_menu']): ?>
        <?php print theme('megamenu_dropdown_tab', array('tab' => $tab, 'key' => $key, 'settings' => $menu_settings))?>
      <?php else: ?>
        <?php print theme('megamenu_tab_theme', array('key' => $key, 'tab' => $tab, 'settings' => $menu_settings))?>
      <?php endif; ?>
    <?php endforeach;?>
  </ul>
  <?php print $show_button; ?>
</div>