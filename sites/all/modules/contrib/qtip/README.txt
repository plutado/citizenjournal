-- SUMMARY --
qTip is another tooltip module for Drupal. By using a simple input filter in your
code you can have a stylish tooltip in just seconds.


-- REQUIREMENTS --
You must download and install the qTip library from
http://craigsworks.com/projects/qtip/download/
This library is licensed under MIT and therefore is not allowed to be hosted on drupal.org

Make sure that you select the 'Production' option. You may download the development
option as well if you would like to check out the code and select to use it on the
admin settings page (under Advanced options), but it is recommended that you use the
compressed 'Production' version of the library on production (live) sites.

Place the extracted contents of the library into /sites/all/libraries/qtip
NOTE: You may have to create the libraries directory
  You should end up with something like this:
    /sites/all/libraries
      /qtip (You will need to create this directory)
        jquery.qtip-1.0.0-rc3.min.js
        REQUIREMENTS
        INSTALL
        LICENSE


-- INSTALLATION --
* Install as usual (see dependency above), see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --
* Once installed, go to admin/config/content/qtip
    * Select how you would like your qTips to display. Save.
* If you want to use simple tooltips via a filter:
    * Go to admin/config/content/formats
        * Click 'configure' on the input filter that you would like to add qTip to
          NOTE: For input filters that have 'HTML filter' enabled (like Filtered HTML), qTip MUST be weighted heavier than HTML filter
            This should be default, but it would be a good idea to check.
    * Save and repeat for as many input filters as you would like.

-- USAGE --
* On a node page enter the filter with one of the following formats:
    Without heading text:
      [qtip:Name of link (target) text|Text to appear in tooltip]
    With heading text:
      [qtip:Name of link (target) text|Header to appear in tooltip|Text to appear in tooltip]
* To use more advanced (including HTML markup) tooltips:
  NOTE: For input filters that have 'HTML filter' enabled (like Filtered HTML), this option will not work!
    * Use the following structure on a node page
        * <span class="qtip-link">
            <span class="qtip-header">Tooltip Heading (optional)</span>
            <span class="qtip-tooltip">Tooltip content</span>
            Link text to tooltip
          </span>
        * You do not have to specify a heading.
        * The tooltip content area can contain any HTML markup.
* Below is an example template of how each tooltip HTML is structured. Use this for custom CSS styling
  NOTE: For performance, these are not created until the cooresponding link is hovered or clicked for the first time (per page load)
    <div id="ui-tooltip-0" role="tooltip" class="ui-tooltip qtip ui-helper-reset ui-tooltip-red ui-tooltip-focus ui-tooltip-pos-rc" aria-hidden="true">
      <div class="ui-tooltip-tip">
        <canvas width="12" height="12"></canvas>
      </div>
      <div class="ui-tooltip-wrapper">
        <div class="ui-tooltip-titlebar">
          <div id="ui-tooltip-0-title" class="ui-tooltip-title">Test Header</div>
        </div>
        <div class="ui-tooltip-content " id="ui-tooltip-0-content">Tooltip Text</div>
      </div>
    </div>
    NOTE: You may have to use !important with your CSS rules as some of the rules are set inline by the qTip library.


-- MAINTAINERS --
Current maintainers:
* Jacob Neher (bocaj) - http://drupal.org/user/582042


-- SPECIAL THANKS --
To Craig Thompson, creator of the qTip jQuery plugin!
http://craigsworks.com