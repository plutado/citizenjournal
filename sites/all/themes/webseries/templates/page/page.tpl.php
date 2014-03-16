<div id="page">

  <div id="wrapper">

    <?php if ($tabs): ?>
      <h2 class="element-invisible">
        <?php print t('Primary tabs'); ?>
      </h2>
      <?php print render($tabs); ?>
    <?php endif; ?>

    <?php print $messages; ?>

    <?php print render($page['help']); ?>

    <?php if ($action_links): ?>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
    <?php endif; ?>

    <div class="content">
      <?php print render($page['content']); ?>
    </div>

  </div>

</div>
