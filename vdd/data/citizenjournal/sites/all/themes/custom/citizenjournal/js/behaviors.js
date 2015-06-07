(function ($) {
  // Remove empty header elements.
  Drupal.behaviors.divIsEmpty = {
    attach: function (context, settings) {
      $('div').filter(function () { return $.trim(this.innerHTML) == "" }).remove();
    }
  };

  Drupal.behaviors.fullpageSlideID = {
    attach: function (context, settings) {

      $('div.section').each(function (i) {
        $(this).attr('id', 'section' + i);
      });

      $('div.section .slide').each(function (i) {
        $(this).attr('id', 'slide-' + i);
      });

      $('.section-main .slide').each(function (i) {

        // Get the image src, so that it may
        // later be used to add as background image
        imageUrl = $(this).find('img').attr('src');

        // Get the image src as 'data-src'
        $(this).find('img').attr('data-src', imageUrl);

        if(typeof imageUrl != 'undefined') {
          $(this).addClass('lazy').attr('data-original', imageUrl);
          $(this).css('background-image', '');
        }

        // Handles vertical slides
        $(this).lazyload({
          effect: "fadeIn"
        });

        // Handles horizontal container
        $(this).lazyload({
          container: ".fp-slidesContainer"
        });

      });

      document.querySelector('#nav-toggle').addEventListener('click', function () {
        this.classList.toggle('active');
      });

    }
  };

  // Function to slabtext the H1 headings
  function slabTextHeadlines() {
    $("h2.slab-text").slabText({
      // Don't slabtext the headers if the viewport is under 380px
      "viewportBreakpoint":380
    });
  };

  // Called one second after the onload event for the demo (as I'm hacking the
  // fontface load event a bit here)

  // Please do not do this in a production environment - you should really use
  // google WebFont loader events (or something similar) for better control
  $(window).load(function() {
    // So, to recap... don't actually do this, it's nasty!
    setTimeout(slabTextHeadlines, 500);
  });

  $(document).ready(function() {
    $('.section-main').fullpage({
      'verticalCentered': false,
      'css3': false,
//          'sectionsColor': ['#8FB98B', '#DE564B', '#EAE1C0'],
      'scrollBar': true,
      'scrollingSpeed': 1700,
      'navigation': true,
      'navigationPosition': 'right',
      'slidesNavigation': true,
      'autoScrolling': false,
      'fitToSection': false
    });
  });

}(jQuery));