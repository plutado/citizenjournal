<!doctype html>
<!-- paulirish.com/2008/conditional-stylesheets-vs-css-hacks-answer-neither/ -->
<!--[if lt IE 7]> <html class="no-js ie6 oldie" lang="en"> <![endif]-->
<!--[if IE 7]>    <html class="no-js ie7 oldie" lang="en"> <![endif]-->
<!--[if IE 8]>    <html class="no-js ie8 oldie" lang="en"> <![endif]-->
<!--[if IE 9]>    <html class="no-js ie9" lang="en"> <![endif]-->
<!-- Consider adding an manifest.appcache: h5bp.com/d/Offline -->
<!--[if gt IE 9]><!--> <html class="no-js" lang="<?php print $language->language; ?>" itemscope itemtype="http://schema.org/Product"> <!--<![endif]-->

<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>

  <title><?php print $head_title; ?></title>

  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=1.0,maximum-scale=1.0">

  <meta name="description" content="" />
  <meta name="keywords" content="" />
  <meta name="author" content="humans.txt">

  <!-- Facebook Metadata /-->
  <meta property="og:description" content="" />
  <meta property="og:site_name" content="" />
  <meta property="og:image" content="" />
  <meta property="og:title" content="" />
  <meta property="og:url" content="" />
  <meta property="og:type" content="website" />


  <!-- Google+ Metadata /-->
  <meta itemprop="name" content="">
  <meta itemprop="description" content="">
  <meta itemprop="image" content="">

  <?php print $styles; ?>
  <script src="sites/all/themes/webseries/js/libs/modernizr-2.6.2.min.js"></script>

</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

  <header>

    <div class="navbar pretty" style="top: 0px;">
      <div class="row">
        <a href="https://davidfugate.com" gumby-trigger="#nav3 ul" class="toggle"><i class="icon-menu"></i></a>
        <h1 class="ten columns logo">
          <a href="https://davidfugate.com/">
            <img gumby-retina="" alt="david plutado fugate" src="sites/all/themes/dpf/logo.png">
          </a>
        </h1>
        <ul class="two columns">
          <!--<li><a href="#">Features</a></li>-->

          <!--
          <li class="episodes">
            <a href="#">Episodes</a>
            <div class="dropdown">
              <ul>
                <li><a href="#">Item</a></li>
                <li><a href="#">Item</a></li>
                <li><a href="#">Item</a></li>
                <li><a href="#">Item</a></li>
                <li><a href="#">Item</a></li>
              </ul>
            </div>
          </li>
          -->
          <li class="about"><a href="#">About the Show</a></li>
          <!-- <li class="field"><input type="search" placeholder="Search" class="search input"></li> -->
        </ul>
      </div>
    </div>

  </header>

  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>


<?php // print $scripts ; ?>

<script gumby-path="/js/libs" src="sites/all/themes/webseries/js/libs/gumby.min.js"></script>
<script src="sites/all/themes/webseries/js/libs/plugins.js"></script>
<script src="sites/all/themes/webseries/js/libs/jquery.fitvids.js"></script>
<script src="sites/all/themes/webseries/js/libs/jquery.equalheights.js"></script> <!-- Equal Heights -->

<script>
  $(window).load(function() {
     equalheight('.row .four.columns');
  });

  $(window).resize(function(){
     equalheight('.row .four.columns');
  });
</script>

<script>
  // Basic FitVids Test
  $("#t_videosurround").fitVids();
</script>

</body>
</html>

