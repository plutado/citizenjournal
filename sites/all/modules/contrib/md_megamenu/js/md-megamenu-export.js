/**
 * @file
 * @author Duynv
 * Date: 4/9/13
 */
(function($) {
    Drupal.behaviors.export_import_cuteslider = {
        attach: function(context, settings) {
            $('input[name=export-button]', context).click(function() {
                var selected = $('#edit-menus input:checked', context).val();
                $.post(settings.basePath+'?q=admin/structure/md-megamenu/export-data', {mids: selected}, function(response) {
                    $('#edit-export-data', context).val(response);
                });
            });
        }
    }
})(jQuery);
