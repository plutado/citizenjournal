<div class="slide">
  <div class="slide-inner <?php if ($background_color == 'rgba(255, 255, 255, 0.65)') { print 'white'; } elseif ($background_color == 'rgba(0, 0, 0, 0.65)') { print 'black'; } else { print 'transparent'; } ?>"
       style="<?php if (!empty($width)) { print 'width: ' . $width . ';'; } ?>
              <?php if (!empty($text_align)) { print 'text-align: ' . $text_align . ';'; } ?>
              <?php if (!empty($bottom_position)) { print 'bottom: ' . $bottom_position . ';'; } ?>
              <?php if (!empty($left_position)) { print 'left: ' . $left_position . ';'; } ?>
  ">

    <?php if($link) : ?>
      <a href="<?php print $link; ?>">
    <?php endif; ?>
    <h2 class="slide-title <?php if ($slabtext == 'yes') { print 'slab-text'; } ?>" style="<?php if (!empty($text_align)) { print 'text-align: ' . $text_align . ';'; } ?>">

      <?php if($title) : ?>
        <span>
          <?php print $title; ?>
        </span>
      <?php endif; ?>

      <?php if($subtitle) : ?>
        <span class="subtitle" style="<?php if (!empty($text_align)) { print 'text-align: ' . $text_align . ';'; } ?>">
          <?php print $subtitle; ?>
        </span>
      <?php endif; ?>
    </h2>
    <?php if($link) : ?>
      </a>
    <?php endif; ?>

    <?php if ($teaser) : ?>
      <p class="teaser" style="<?php if (!empty($text_align)) { print 'text-align: ' . $text_align . ';'; } ?>">
        <?php print $teaser; ?>
      </p>
    <?php endif; ?>

    <div class="hide">
      <?php print $bg; ?>
    </div>

  </div>

</div>
