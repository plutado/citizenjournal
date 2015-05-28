<?php

/**
 * @file
 * default page layout template.
 */
?>

<?php print $content['menu']; ?>

<header class="ha-header ha-header-small" id="ha-header">
  <div class="ha-header-perspective">
    <div class="ha-header-front">
      <span>
        <a href="/" title="Home" alt="David Fugate">
          <img width="215" src="/sites/all/themes/custom/citizenjournal/images/dpf-logo.svg">
        </a>
      </span>
      <nav>
        <a class="menu-anchor" id="nav-toggle">
          <button id="trigger-overlay" type="button">
            <!-- &#9776; -->
            <span></span>
          </button>
        </a>
        <a class="menu-close" style="display: none;">
          <!-- &#10006; -->
        </a>
      </nav>
    </div>

  </div>
</header>

<div class="container">

  <div class="content">

    <?php print $content['header']; ?>

    <div class="main">
      <?php print $content['main_content']; ?>
    </div>

    <?php print $content['footer']; ?>

  </div>

</div>

<div class="overlay overlay-hugeinc">
  <nav>
    <ul>
      <li><a href="#">Home</a></li>
      <li><a href="#">About</a></li>
      <li><a href="#">Work</a></li>
      <li><a href="#">Clients</a></li>
      <li><a href="#">Contact</a></li>
    </ul>
  </nav>
</div>

<?php if (!path_is_admin(current_path())) : ?>
  <?php drupal_add_js( drupal_get_path('theme', 'citizenjournal') . '/js/modernizr.custom.js', array('type' => 'file', 'scope' => 'header')); ?>
  <?php drupal_add_js( drupal_get_path('theme', 'citizenjournal') . '/js/classie.js', array('type' => 'file', 'scope' => 'footer')); ?>
  <?php drupal_add_js( drupal_get_path('theme', 'citizenjournal') . '/js/demo1.js', array('type' => 'file', 'scope' => 'footer')); ?>
<?php endif; ?>
