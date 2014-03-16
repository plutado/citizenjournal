<?php
  drupal_add_js(path_to_theme() . '/js/iscroll-min.js');
  drupal_add_js(path_to_theme() . '/js/libs/jquery.equalheights.js');
?>

<?php
  drupal_add_js(path_to_theme() . '/js/classie.js');
  drupal_add_js(path_to_theme() . '/js/gnmenu.js');
?>

<div<?php print $attributes; ?>>

  <ul id="gn-menu" class="gn-menu-main">
    <li class="gn-trigger">
      <a class="gn-icon gn-icon-menu"><span>Menu</span></a>
      <nav class="gn-menu-wrapper">
        <div class="gn-scroller">
          <ul class="gn-menu">
            <!--
            <li class="gn-search-item">
              <input placeholder="Search" type="search" class="gn-search">
              <a class="gn-icon gn-icon-search"><span>Search</span></a>
            </li>
            -->
            <li>
              <a class="gn-icon gn-icon-article">Blog Posts</a>
            <!--
            <ul class="gn-submenu">
              <li><a class="gn-icon gn-icon-cog">Web Development</a></li>
            </ul>
            -->
            </li>
            <li><a class="gn-icon gn-icon-videos">Videos</a></li>
            <li><a class="gn-icon gn-icon-pictures">Photo Galleries</a></li>
            <li><a class="gn-icon gn-icon-earth">Best of the Web</a></li>
            <li><a class="gn-icon gn-icon-file">Resume</a></li>
            <li><a class="gn-icon gn-icon-info">About This Site</a></li>
            <!--<li><a class="gn-icon gn-icon-videos">Resume</a></li>-->
          </ul>
        </div><!-- /gn-scroller -->
      </nav>
    </li>
    <li class="logo-li">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('david plutado fugate'); ?>" rel="home" class="site-logo">
        dpf
      </a>
    <?php endif; ?>
    </li>
    <li><!--<a class="codrops-icon codrops-icon-prev" href=""><span>Previous Article</span></a>--></li>
    <li><!--<a class="codrops-icon codrops-icon-drop" href=""><span>Next Article</span></a>--></li>
  </ul>

  <header class="header" role="banner">
    <?php if ($site_name || $site_slogan): ?>
      <?php if ($site_name): ?>
        <h1 class="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </h1>
      <?php endif; ?>

      <?php if ($site_slogan): ?>
        <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
      <?php endif; ?>
    <?php endif; ?>
  </header>

  <?php print render($page['header']); ?>
  <?php print render($page['navigation']); ?>

  <div id="content">

      <div class="main">
        <div class="content" role="main">
          <?php print render($page['highlighted']); ?>
          <?php // print $breadcrumb; ?>
          <a id="main-content"></a>

          <?php print $messages; ?>
          <?php print render($tabs); ?>

          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>


          <?php print render($page['help']); ?>
          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>

          <div class="feed-icons">
            <?php print $feed_icons; ?>
          </div>

        </div>

        <?php print render($page['sidebar_first']); ?>
        <?php print render($page['sidebar_second']); ?>
      </div>
  </div>

  <footer class="footer" role="contentinfo">
    <?php print render($page['footer']); ?>
  </footer>

</div>
