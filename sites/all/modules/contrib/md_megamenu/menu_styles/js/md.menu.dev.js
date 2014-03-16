/*
 * jQuery MegaMenu v1.1
 * http://megamenu.megadrupal.com/
 *
 * Copyright 2013 MegaDrupal
 */

(function($){

    $(window).resize(function () {
        $('.mdmegamenu').each(function() {
            var self = $(this),
                menuWidth = self.outerWidth(true);
            var fullwidth = self.width();
            if (self.hasClass("md-vertical")) {  // vertical menu
                // Right to left
                if (self.hasClass("md-vertical-rtl")) {
                    var ulwidth = $('> ul', self).width();
                    var ulright = ($(window).width() - ($('> ul', self).offset().left + $('> ul', self).outerWidth()));
                    fullwidth = $(window).width() - ulwidth - ulright - 20;
                    if (fullwidth > 960) fullwidth = 960 - ulwidth;
                    $('div.mm-customwidth', self).each(function() {
                        var thiswidth = parseInt($(this).data("width"));
                        if(fullwidth < thiswidth) {
                            $(this).addClass('mm-fullwidth');
                        } else {
                            $(this).width(thiswidth);
                            $(this).removeClass('mm-fullwidth');
                        }
                    });
                    if(ulwidth > ($(window).width() - ulright - 20) / 2) {
                        $('.mm-container', self).each(function() {
                            var parent = $(this).parent();
                            $(this).css({top: parent.height(), left: 0});
                            if($(this).hasClass("mm-fullwidth"))
                                $(this).width(self.width());
                        });
                    } else {
                        $('div.mm-fullwidth', self).width(fullwidth);
                    }
                } else {
                    // Left to right
                    var ulwidth = $('> ul', self).width();
                    var ulleft = $('> ul', self).offset().left;
                    fullwidth = $(window).width() - ulwidth - ulleft - 20;
                    if (fullwidth > 960) fullwidth = 960 - ulwidth;
                    $('div.mm-customwidth', self).each(function() {
                        var thiswidth = parseInt($(this).data("width"));
                        if(fullwidth < thiswidth) {
                            $(this).addClass('mm-fullwidth');
                        } else {
                            $(this).width(thiswidth);
                            $(this).removeClass('mm-fullwidth');
                        }
                    });
                    if(ulwidth > ($(window).width() - ulleft - 20) / 2) {
                        $('.mm-container', self).each(function() {
                            var parent = $(this).parent();
                            $(this).css({top: parent.height(), left: 0});
                            if($(this).hasClass("mm-fullwidth"))
                                $(this).width(self.width());
                        });
                    } else {
                        $('div.mm-fullwidth', self).width(fullwidth);
                    }
                }

            } else {
                if(self.hasClass('mm-fixed-bottom')) {
                    _tmpheight = self.outerHeight() - parseInt(self.css('borderTopWidth')) - parseInt(self.css('borderBottomWidth'));
                    $('> ul > li', self).each(function() {
                        $("> .mm-container", $(this)).css('bottom', _tmpheight);
                    });
                } else {
                    $('> ul > li', self).each(function() {
                        $("> .mm-container", $(this)).css('top', $(this).height() + $(this).position().top);
                    });
                }
                $('div.mm-customwidth', self).each(function() {
                    var thiswidth = parseInt($(this).data("width"));
                    /*if(fullwidth < thiswidth) {
                        $(this).css({'left': 0, 'width': '100%'});
                        $(this).addClass('mm-fullwidth');
                    } else {*/
                        $(this).width(thiswidth);
                        $(this).removeClass('mm-fullwidth');
                    //}
                    var position = $(this).parent("li").position(),
                        parentLeft = position.left,
                        thisWidth = $(this).width(),
                        thisRight = parentLeft + thisWidth;
                    if (self.hasClass('mm-fixed-bottom') || self.hasClass('mm-fixed-top')) {
                        menuWidth = menuWidth * 2;
                    }
                    if(thisRight > menuWidth) {
                        mainSubLeft = menuWidth - thisWidth;
                        if($.browser.msie) {
                            if ((parseInt($.browser.version, 10) == 7) || (parseInt($.browser.version, 10) == 8) || (parseInt($.browser.version, 10) == 9))
                                 mainSubLeft = menuWidth - thisWidth + 5;
                        }
                        $(this).css('left', mainSubLeft);
                    } else {
                        $(this).css('left', parentLeft);
                    }
                });
                $(".mm-dropdown", self).each(function() {
                    $(this).children('.mm-container').css('left', $(this).position().left);
                });
            }



            $("div.mm-sub", self).each(function() {
                var cols = $(this).children(".background-color").not(".mmg_12");
                $(cols).each(function() {
                    var col = $(this),
                        _height = 0,
                        mmcontainer = col.parents(".mm-container");

                    mmcontainer.show();
                    _height = col.parent().height();
                    if(_height > 0) {
                        col.height(_height);
                    }
                    mmcontainer.hide();
                });
            });
        });
    });

    $.fn.megadrupalMenu = function(options){
        function megaOver(){
            megaAction(this);
        }
        function megaOut(){
            megaActionClose(this);
        }

        function megaReset(megaMenu){
            $('li', megaMenu).removeClass('mm-hover');
            $('.mm-container', megaMenu).hide();
        }
        function megaAction(obj){
            var $dropDown = $('> .mm-container', obj);
            $(obj).parents(".mdmegamenu").find(".mm-container").not($(obj).parents(".mm-container")).hide();
            $(obj).addClass('mm-hover');
            if ($dropDown.length > 0 && $dropDown.is(':hidden') == false) return;
            if($dropDown.is(':hidden')) {
                switch(opts.effects.effectTypeOpen)
                {
                    case 'slide':
                        $dropDown.stop(true, true).delay(opts.timeBeforeOpening).slideDown(opts.effects.effectSpeedOpen, opts.effects.effectOpen);
                        break;
                    case 'fade':
                        $dropDown.stop(true, true).delay(opts.timeBeforeOpening).fadeIn(opts.effects.effectSpeedOpen, opts.effects.effectOpen);
                        break;
                    default :
                        $dropDown.stop(true, true).delay(opts.timeBeforeOpening).show();
                }
            }
        }
        function megaActionClose(obj){
            var $dropDown = $('> .mm-container', obj);
            if($dropDown.length > 0 && $dropDown.is(':hidden') == false) {
                switch(opts.effects.effectTypeClose)
                {
                    case 'slide':
                        $dropDown.stop(true, true).delay(opts.timeBeforeClosing).slideUp(opts.effects.effectSpeedClose, opts.effects.effectClose, function(){$(obj).removeClass('mm-hover');});
                        break;
                    case 'fade':
                        $dropDown.stop(true, true).delay(opts.timeBeforeClosing).fadeOut(opts.effects.effectSpeedClose, opts.effects.effectClose, function(){$(obj).removeClass('mm-hover');});
                        break;
                    default :
                        $dropDown.stop(true, true).delay(opts.timeBeforeClosing).hide();
                        $(obj).removeClass('mm-hover');
                }
            }
            else {
                $(obj).removeClass('mm-hover');
            }
        }

        var opts = $.extend({
            effects : {
                effectSpeedOpen : 300,
                effectSpeedClose : 200,
                effectTypeOpen : 'slide',
                effectTypeClose : 'slide',
                effectOpen : 'linear',
                effectClose : 'linear'
            },
            timeBeforeOpening : 100,
            timeBeforeClosing : 200,
            trigger : "hover-intent",
            arrow: false,
            vertical: false,
            verticalDirection: "ltr", // ltr and rtl, default is ltr
            subAlign: "middle"
        }, options);
        //Mobile - iOS
        var deviceAgent = navigator.userAgent.toLowerCase();
        var is_Mobile = deviceAgent.match(/(iphone|ipod|ipad|android|"windows phone")/);

        return this.each(function() {
            var megaMenu = $(this),
                megaMenuWrap = megaMenu.parent(),
                menuItem = $("li.mm-parent", megaMenu);

            if (megaMenuWrap.hasClass('mm-fixed-bottom') || megaMenuWrap.hasClass('mm-fixed-top')){
                $('.mm-toggle', megaMenuWrap).click(function(){
                    $(this).toggleClass('mm-toggle-show');
                    megaMenuWrap.toggleClass('mm-toggle-hide');
                    $('> ul', megaMenuWrap).slideToggle();
                    return false;
                })
            }


            menuItem.each(function() {
                var self = $(this);
                if(opts.arrow) {
                    $("> a", self).addClass('with-arrow').append('<span class="mm-arrow"></span>');
                }

                if (opts.vertical) {
                    if(opts.subAlign == "middle") {
                        var position = self.position(),
                            parentTop = position.top,
                            parentHeight = self.height(),
                            mainSub = $('> .mm-container', this),
                            mainSubHeight = mainSub.height(),
                            mainSubTop = (mainSubHeight/2 - parentHeight/2);
                        if(parentTop > mainSubTop)
                            mainSub.css('top', -mainSubTop);
                        else {
                            mainSub.css('top', -parentTop);
                        }
                    }
                }
            });
            /* Actions on parents links */
            if(opts.trigger === "hover") {
                menuItem.hover(megaOver, megaOut);
            } else if(opts.trigger === "click") {
                $('body').mouseup(function(e){
                    if(!$(e.target).parents('.mm-hover').length){
                        megaReset(megaMenu);
                    }
                });

                $('> a', menuItem).click(function(e){
                    var $parentLi = $(this).parent();
                    if(!$parentLi.hasClass('mm-hover')){
                        megaAction($parentLi);
                        e.preventDefault();
                    }
                });
            } else {
                var config = {
                    sensitivity: 2, // number = sensitivity threshold (must be 1 or higher)
                    interval: 100, // number = milliseconds for onMouseOver polling interval
                    over: megaOver, // function = onMouseOver callback (REQUIRED)
                    timeout: 400, // number = milliseconds delay before onMouseOut
                    out: megaOut // function = onMouseOut callback (REQUIRED)
                };
                menuItem.hoverIntent(config);
            }

            if (is_Mobile) {
                var text_arrow = "&darr;";
                if (opts.vertical) text_arrow = "&rarr;";
                $('<span class="mm-close">&times;</span>').appendTo($("> li.mm-parent > a", megaMenu)).hide().click(function(e) {
                    e.preventDefault();
                    "open" == $(this).attr("data-mega-status") ? (megaActionClose($(this).parents("li.mm-parent")[0]), $(this).html(text_arrow).attr("data-mega-status", "closed")) : (megaAction($(this).parents("li.mm-parent")[0]), $(this).html("&times;").attr("data-mega-status", "open"));
                    return false;
                });
                $("> li.mm-parent", megaMenu).hover(function(e){
                    e.preventDefault();
                    $(this).find(".mm-close").html("&times;").attr("data-mega-status", "open").show();
                    $(this).find(".mm-arrow").hide();
                }, function(e){
                    $(this).find(".mm-close").hide();
                    $(this).find(".mm-arrow").show();
                });
            }
            $(window).resize();
        });
    };
})(jQuery);