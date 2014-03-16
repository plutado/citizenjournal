(function ($) {
Drupal.behaviors.qtip = {
  attach: function(context) {

    // Set delay on click to immediate
    if (Drupal.settings.qtip.show_event_type == 'click') {
      show_delay = 1;
    }
    else {
      show_delay = 140; // This is the default qTip value, set for hover links
    }

    // Determine how to position the tooltip
    if (Drupal.settings.qtip.show_speech_bubble_tip) {
      // Set the proper qtip speech-bubble tip position
      if (Drupal.settings.qtip.show_speech_bubble_tip_side) {
        switch_position = Drupal.settings.qtip.tooltip_position.split('_');
        // We do not want to put tooltip on it's side if it is being displayed
        // in the center or side of an element
        if (switch_position[1] == 'center') {
          tip_position = Drupal.settings.qtip.tooltip_position;
        }
        else {
          tip_position = switch_position[1] + ' ' + switch_position[0];
        }
      }
      // Otherwise just set it to the same value as the tooltip
      else {
        tip_position = Drupal.settings.qtip.tooltip_position;
      }
    }
    else {
      tip_position = false;
    }
    
    // Is a custom style declared by the admin?
    if(Drupal.settings.qtip.color == 'custom-color') {
      Drupal.settings.qtip.color = Drupal.settings.qtip.custom_color;
    }

    // Do we want a shadow to show under the tooltip?
    if(Drupal.settings.qtip.show_shadow) {
      style_classes = 'ui-tooltip-shadow ' + Drupal.settings.qtip.color;
    }
    else {
      style_classes = Drupal.settings.qtip.color;
    }
    
    // Do we want to show the tooltips with rounded corners?
    if(Drupal.settings.qtip.rounded_corners) {
      style_classes += ' ui-tooltip-rounded';
    }
    
    //Do we want a solid tip to display
    if (Drupal.settings.qtip.show_speech_bubble_tip_solid) {
      solid_tip = false;
    }
    else {
      solid_tip = 5;
    }

/*** Standard Settings ***/
    $('.qtip-link').each(function() {
      if(Drupal.settings.qtip.show_event_type == 'click') {
        $(this).addClass('ui-tooltip-click');
      }
      
      // if there is a title associated with this qtip...
      if ($(this).children('.qtip-header').length) {
        tooltip_title = $(this).children('.qtip-header').html();
      }
      // if there isn't we don't want a blank title area to show on the qtip...
      else {
        tooltip_title = false;
      }
      
      build_qtip(this, 'node');
    });
    
/*** Additional Elements ***/
    if(Drupal.settings.qtip.additional_elements) {
      $(Drupal.settings.qtip.additional_elements).each(function() {
        $(this).addClass('qtip-additional-element');
        if(Drupal.settings.qtip.show_event_type == 'click') {
          $(this).addClass('ui-tooltip-click');
        }
        
        // if there is a title associated with this qtip...
        if ($(this).children('.qtip-header').length) {
          tooltip_title = $(this).children('.qtip-header').html();
        }
        // if there isn't we don't want a blank title area to show on the qtip...
        else {
          tooltip_title = false;
        }
        
        build_qtip(this, 'node');
      });
    }

/*** Webform Settings ***/
    // Does the admin even want the descriptions to show up in a tooltip?
    if (Drupal.settings.qtip.show_webform_descriptions) {
      /*
       form-text - works well
       form-textarea - works, but width can throw off the tooltip
       form-radios - works, but the radios element wrapper is 100% width, so throws off tooltip like form-textarea
       form-select - works well - should maybe have something like mouseenter or something for usability
      */
      // Elements where description is a sibling to the selected element
      $('form.webform-client-form .form-text,' +
        'form.webform-client-form .form-select').each(function() {
        description = $(this).siblings('.description');
        description.css('display', 'none');
        tooltip_title = false;
        show_delay = 1;
        build_qtip(this, 'form', description.html());
      });
  
      // Elements where description is a sibling to the PARENT of the selected element
      $('form.webform-client-form .form-radios,' +
        'form.webform-client-form .form-textarea').each(function() {
        description = $(this).parent().siblings('.description');
        description.css('display', 'none');
        tooltip_title = false;
        show_delay = 1;
        
        build_qtip(this, 'form', description.html());
      });
    }
    
    
    
    function build_qtip(el, type, desc) {
      if (type == 'form') {
        show_text = desc ? desc : '';
        // By default, the description text is wrapped inside <p>
        // Since we are putting this in a tooltip we want to remove this
        // and any other tags that might possibly get set
        show_text = show_text.replace(/(<.*?>)/ig,"");
        set_my = 'left_center';
        tip_position = 'left_center';
        set_at = 'right_center';
        show_event = 'focus';
        hide_event = 'blur';
      }
      else { // "Normal" tooltip
        show_text = $(el).children('.qtip-tooltip');
        set_my = Drupal.settings.qtip.tooltip_position;
        set_at = Drupal.settings.qtip.target_position;
        show_event = Drupal.settings.qtip.show_event_type;
        hide_event = Drupal.settings.qtip.hide_event_type;
      }
      $(el).qtip({
        content: {
          text: show_text,
          title: {
            text: tooltip_title
          }
        },
        position: {
          my: set_my, // my = speech bubble position on tooltip
          at: set_at, // at = where on link text tooltip will appear
          adjust: {
            screen: true // Keeps tooltip within visible window
          }
        },
        style: {
          classes: style_classes,
          tip: {
            corner: tip_position, // Position of speech bubble tip...false will not display tip
            border: solid_tip, // parseInt(Drupal.settings.qtip.border_width)
            width: parseInt(Drupal.settings.qtip.speech_bubble_size),
            height: parseInt(Drupal.settings.qtip.speech_bubble_size)
          }
        },
        show: {
          event: show_event,
          solo: true, // Determines whether or not the tooltip will hide all others when the show.event is triggered on the show.target. 
          delay: show_delay
        },
        hide: {
          event: hide_event,
          fixed: true //When set to true, the tooltip will not hide if moused over, allowing the contents to be clicked and interacted with.
        }
      });
    }
  }
};
})(jQuery);
