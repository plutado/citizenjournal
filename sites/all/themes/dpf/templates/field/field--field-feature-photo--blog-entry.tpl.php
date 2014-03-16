<?php foreach ($items as $delta => $item) : ?>
  <div class="swiper-slide">
    <div class="inner">
      <?php print render($item); ?>
    </div>
  </div>
<?php endforeach; ?>
