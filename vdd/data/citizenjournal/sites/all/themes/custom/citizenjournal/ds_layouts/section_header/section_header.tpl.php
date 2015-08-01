<section class="par-section-header <?php print $classes . ' clearfix ' . $field_par_section_full[0]['value'] . ' ' . $field_par_section_type[0]['value']; ?>">

  <?php if ($title && $title != "&nbsp;"): ?>
    <h1><?php print $title; ?></h1>
  <?php endif; ?>

  <?php if ($subhead && $subhead != "&nbsp;"): ?>
    <p><?php print ($subhead); ?></p>
  <?php endif; ?>

  <?php if (($call_to_action && $call_to_action != "&nbsp;") && ($link && $link != "&nbsp;")): ?>
    <div class="call-to-action">
      <?php print l($call_to_action, $link, array('attributes' => array ('class' => 'button'))); ?>
    </div>
  <?php endif; ?>

</section>
