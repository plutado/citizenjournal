<!DOCTYPE html>
<!--[if lt IE 7]> <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>    <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>    <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
<head>
  <meta charset="utf-8">
  <title><?php print $head_title; ?></title>
  <link rel="shortcut icon" href="../favicon.ico"> 
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=1.0,maximum-scale=1.0">
  <?php print $styles; ?>
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

  <!--[if lt IE 7]>
    <p class="chromeframe">
      You are using an <strong>outdated</strong> browser. Please <a href="http://browsehappy.com/">upgrade your browser</a> 
      or <a href="http://www.google.com/chromeframe/?redirect=true">activate Google Chrome Frame</a> to improve your experience.
    </p>
  <![endif]-->
  
  <header class="main">    
    <!-- if site logo -->
    <?php if ($logo) : ?>
      <a href="/" class="ss-list">
        <img src="<?php print $logo; ?>" ></img>
      </a>   
    <?php endif; ?> 
    <!-- /END site logo -->
  </header>  

    <?php print $page; ?>

  <footer class="main">
    
  </footer>

  <?php print $scripts; ?>
  
  <script>
    // Basic FitVids Test
    $(".content").fitVids({ customSelector: "iframe[src^='http://vimeo.com']"});  
    $(".content").fitVids({ customSelector: "iframe[src^='http://youtube.com']"});  
  </script>       

</body>
</html>