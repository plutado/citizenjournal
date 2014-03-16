(function($) {
	$(document).ready(function(){

        Drupal.menuTab.init();
        Drupal.menuItem.init();
		Drupal.menuLayout.init();




		$("input.numeric").numeric({ negative: false });
        $('#submnu_full_width').change(function() {
            if ($(this).is(':checked')) {
                $('#mnu-sub-width').hide();
            } else {
                $('#mnu-sub-width').show();
            }
        });
		
		blocktype = $('#blocklist .md-listleft li');
		blocktype_length = blocktype.length;
		if (blocktype_length > 9) {
			blocktype.slice(7,blocktype_length).hide();
			$('#blocklist .md-listleft').append('<div id="showallblocks">Show all</div>');
			$('#showallblocks').click(function(){
				blocktype.show();
				$(this).remove();
			})
		}
		

		function getFlyMenuItem(ul) {
			var lstItem = [];
			$("> li", ul).each(function() {
				var setting = $.stringToObject($(this).find("input.setting").val());
				var subItems = $(this).has("ul") ? getFlyMenuItem($("> ul", $(this))) : null;
				lstItem.push({setting: setting, subItems: subItems});
			});
			return lstItem;
		}

		$("#edit-save-btn, #edit-save-continue-btn").click(function() {
			var data = [];
			$("#md-tabs .ui-tabs-nav a.tab-link").each(function() {
				var tab = $($(this).attr("href"));
				var subMenu = [];
				var settings = $.stringToObject(tab.find("input.settings").val());
				if(settings.mnu_fly_type) {
					$tree = tab.find("div.tree");
					if($tree.has("ul")) {
						subMenu = getFlyMenuItem($("> ul", $tree));
					}
				} else {
					tab.find(".md-row").each(function() {
						var rowItems = [];
						$(this).find("div.md-col").each(function() {
							var colItems = [];
							$(this).find("div.md-bl").each(function() {
								var obj = $(this).find("input.setting").val();
								colItems.push($.unserialize(obj));
							});
							rowItems.push(colItems);
						});
						if(rowItems.length > 0) 
							subMenu.push(rowItems);
					});
				}
				data.push({
					settings: settings,
					subMenu: subMenu
				});
			});
			$("textarea.md-megamenu-data-save").val($.objectToString(data));
		});	
		
		$('a.choose-image-link').live('click',function () {
			var _self = $(this);
	      	Drupal.media.popups.mediaBrowser(function (mediaFiles) {
	        	var icon = mediaFiles[0];
	        	var preview = _self.prev().empty();
	        	var iconElement = $('<img/>').attr('src', icon.url);
	        	preview.append(iconElement);        	
	        	_self.next().val("id=" + icon.fid + "&url=" + icon.url);
	        });
		 });

        Drupal.menuTab.initTab();
	});
	
	$.fn.loadingDialog = function() {
        $(this).html('<div class="divloading"></div>');
        $(this).parent().find("button.ui-button").attr("disabled", true);
        return this;
    }
    $.fn.unLoadingDialog = function() {
        $(this).parent().find("button.ui-button").attr("disabled", false);
        return this;
    }
		
})(jQuery);