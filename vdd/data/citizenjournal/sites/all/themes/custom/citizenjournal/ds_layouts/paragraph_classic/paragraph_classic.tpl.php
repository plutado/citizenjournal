<section class="post-image <?php if ($text_align) { print trim($text_align); } ?>">
  <?php if (!$media_alignment) : ?>
    <div class="full-wrapper">
  <?php endif; ?>

    <div class="<?php print (str_replace(' ', '-', strtolower($media_width))) ?> <?php if ($media_alignment) { print $media_alignment; } else { print 'none'; } ?>">
      <?php print $media; ?>
    </div>

  <?php if (!$media_alignment) : ?>
    </div>
  <?php endif; ?>

  <<?php print $headline_size; ?>>
    <?php print $headline; ?>
    <?php if($subtitle) : ?>
      <span class="subtitile">
          <?php print $subtitle; ?>
        </span>
    <?php endif; ?>
  </<?php print $headline_size; ?>>

  <?php print $body_copy; ?>

</section>
