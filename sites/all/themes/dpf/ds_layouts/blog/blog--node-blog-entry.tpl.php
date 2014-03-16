<?php
/**
 * @file
 * blog--node-blog-entry.tpl.php
 * display suite template for story content type
 */
?>

<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['branding']: Items for the branding region.
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see omega_preprocess_page()
 */
?>

<div class="subheadline">
  <?php print strip_tags($subtitle); ?>
</div>

<?php if (!empty($video_embed)) : ?>
  <div class="video-embed">
    <?php print $video_embed; ?>
  </div>
<?php endif; ?>

<?php if ((isset($variables['field_feature_photo'][0])) && (!isset($variables['field_feature_photo'][1]))) : ?>
  <div data-snap-ignore="true" class="swiper-wrapper">
    <div class="single-slide">
      <div class="inner">
        <img class="image" src="<?php print image_style_url('1400x933', $variables['field_feature_photo'][0]['uri']); ?>"></img>

        <?php if (!empty($variables['field_feature_photo'][0]['title']) || !empty($variables['field_feature_photo'][0]['alt'])) : ?>
          <div class="caption-wrapper">
            <?php if (!empty($variables['field_feature_photo'][0]['title'])) : ?>
              <div class="caption">
                <?php print $variables['field_feature_photo'][0]['title'];?>
              </div>
            <?php endif; ?>
            <?php if (!empty($variables['field_feature_photo'][0]['alt'])) : ?>
              <div class="credit">
                <?php print $variables['field_feature_photo'][0]['alt']; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

      </div>
    </div>
  </div>
<?php endif; ?>

<?php if (isset($variables['field_feature_photo'][1])) : ?>

  <div data-snap-ignore="true" class="swiper-container">
    <div class="swiper-wrapper">
      <?php print $variables['gallery_photos']; ?>
    </div>
  </div>

  <div class="pagination"></div>

<?php endif; ?>


<div class="constrain" id="content-body">

  <aside class="left-col">

    <div class="contributor-info">
      <?php $node_author = user_load($node->uid); ?>

      <?php $img_url = $node_author->field_user_photo[LANGUAGE_NONE][0]['uri']; ?>
      <div class="author-photo">
        <img src="<?php print image_style_url("medium", $img_url); ?>" />
      </div>
      <div class="blurb">
        <?php print l($node_author->field_contributor_name[LANGUAGE_NONE][0]['safe_value'], $node_author->field_contributor_link[LANGUAGE_NONE][0]['url']); ?>
        <?php print $node_author->field_blurb['und'][0]['safe_value']; ?>
      </div>
    </div> <!-- /END .contributor-info -->

    <div class="comments-submitted">
      <a href="#comments">
        <img src="http://<?php print $_SERVER["SERVER_NAME"] . '/' . drupal_get_path('theme', 'dpf') ?>/images/comment.png" />
        <div class="comment-count-total"><?php print $comment_count ?></div>
        <?php if ($comment_count == 1) : ?>
          <span class='label-comments'>
            <?php print 'comment'; ?>
          </span>
        <?php else : ?>
          <span class='label-comments'>
            <?php print 'comments'; ?>
          </span>
        <?php endif; ?>
      </a>
    </div>

    <?php if ($node->field_weblinks): ?>
      <div class='weblinks'>
        <h3>Related Links</h3>
        <ul>
          <?php for ($t = 0; $t < 5; $t++) {  ?>
            <?php if ($node->field_weblinks[$t]) { ?>
            <li class='weblink'>
              <?php print render($node->field_weblinks[$t]); ?>
            </li>
            <?php } ?>
          <?php } ?>
        </ul>
      </div>
    <?php endif; ?>

    <?php print $sidebar; ?>

  </aside><!--/.right-col-->

  <div class="primary-col">

    <?php print $body; ?>

    <?php if ($display_submitted): ?>
      <div class="submitted-info">
        <span class="submitted">— Last Updated: <?php print date('F j, Y - g:ia', $node->changed); ?> — <?php // print $name; ?></span>
      </div>
    <?php endif; ?>

    <ul id="node-navigation">
      <?php if (pn_node($node, 'p')) : ?><li class="prev"><?php print pn_node($node, 'p'); ?></li><?php endif; ?>
      <?php if (pn_node($node, 'n')) : ?><li class="next"><?php print pn_node($node, 'n'); ?></li><?php endif; ?>
    </ul>

  </div><!--/.primary-col-->

</div><!--/#content-body-->


<section id="comments">
  <?php print $comments; ?>
</section>


<?php if (isset($variables['field_feature_photo'][1])) : ?>

  <script type="text/javascript" src="http://<?php print $_SERVER["SERVER_NAME"] . '/' . drupal_get_path('theme', 'dpf') ?>/js/jquery-1.9.1.min.js"></script>
  <script src="http://<?php print $_SERVER["SERVER_NAME"] . '/' . drupal_get_path('theme', 'dpf') ?>/js/idangerous.swiper-2.0.min.js"></script>

  <script type="text/javascript">

    $(function(){
      var gallery = $('.swiper-container').swiper({
        slidesPerView:'auto',
        initialSlide: 1,
        centeredSlides: true,
        pagination:'.pagination',
        paginationClickable: true,
        resizeReInit: true,
        keyboardControl: true,
        grabCursor: true,
        onImagesReady: function(){
          changeSize()
        }
      })

      gallery.getFirstSlide().clone().append();

      function changeSize() {
        //Unset Width
        $('.swiper-slide').css('width','')
        //Get Size
        var imgWidth = $('.swiper-slide img').width();
        if (imgWidth+40>$(window).width()) imgWidth = $(window).width()-40;
        //Set Width
        $('.swiper-slide').css('width', imgWidth+50);
      }

      function changeHeight() {
        $('.swiper-container').css('height', '');

        var imgHeight = $('.swiper-slide img').height();
        $('.swiper-container').css('max-height', imgHeight+110);
      }

      changeSize()
      gallery.resizeFix(true)
      changeHeight()

      //Smart resize
      $(window).resize(function(){
        changeSize()
        gallery.resizeFix(true)
        changeHeight()
      })

      $('.swiper-pagination-switch:last-child').remove();

    })

  </script>

<?php endif; ?>
