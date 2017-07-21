/* $Id: PDFlib_objc.h,v 1.8.2.9.2.2 2016/11/18 17:42:06 rjs Exp $
 *
 * Wrapper code for the PDFlib Objective-C binding
 *
 */

#import <Foundation/Foundation.h>
#import <Foundation/NSException.h>
#import "pdflib.h"
    
        
@interface PDFlibException : NSException
{
    NSInteger _errnum;
    NSString *_apiname;
}
- (id) initWithErrmsg:(NSString *)errmsg errnum: (NSInteger) aErrnum apiname: (NSString *)aApiname;
- (NSInteger) get_errnum;
- (NSString *) get_apiname;
- (NSString *) get_errmsg;

@end


@interface PDFlib : NSObject {
    PDF *_p;
}   

 
- (void) activate_item: (NSInteger) id;
- (NSInteger) add_bookmark: (NSString *) text parent: (NSInteger) parent open: (NSInteger) open;
- (void) add_launchlink: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury filename: (NSString *) filename;
- (void) add_locallink: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury page: (NSInteger) page optlist: (NSString *) optlist;
- (void) add_nameddest: (NSString *) name optlist: (NSString *) optlist;
- (void) add_note: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury contents: (NSString *) contents title: (NSString *) title icon: (NSString *) icon open: (NSInteger) open;
- (NSInteger) add_path_point: (NSInteger) path x: (double) x y: (double) y type: (NSString *) type optlist: (NSString *) optlist;
- (void) add_pdflink: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury filename: (NSString *) filename page: (NSInteger) page optlist: (NSString *) optlist;
- (NSInteger) add_portfolio_file: (NSInteger) folder filename: (NSString *) filename optlist: (NSString *) optlist;
- (NSInteger) add_portfolio_folder: (NSInteger) parent foldername: (NSString *) foldername optlist: (NSString *) optlist;
- (NSInteger) add_table_cell: (NSInteger) table column: (NSInteger) column row: (NSInteger) row text: (NSString *) text optlist: (NSString *) optlist;
- (NSInteger) add_textflow: (NSInteger) textflow text: (NSString *) text optlist: (NSString *) optlist;
- (void) add_thumbnail: (NSInteger) image;
- (void) add_weblink: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury url: (NSString *) url;
- (void) align: (double) dx dy: (double) dy;
- (void) arc: (double) x y: (double) y r: (double) r alpha: (double) alpha beta: (double) beta;
- (void) arcn: (double) x y: (double) y r: (double) r alpha: (double) alpha beta: (double) beta;
- (void) attach_file: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury filename: (NSString *) filename description: (NSString *) description author: (NSString *) author mimetype: (NSString *) mimetype icon: (NSString *) icon;
- (NSInteger) begin_document: (NSString *) filename optlist: (NSString *) optlist;
- (void) begin_dpart: (NSString *) optlist;
- (void) begin_font: (NSString *) fontname a: (double) a b: (double) b c: (double) c d: (double) d e: (double) e f: (double) f optlist: (NSString *) optlist;
- (void) begin_glyph: (NSString *) glyphname wx: (double) wx llx: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury;
- (void) begin_glyph_ext: (NSInteger) uv optlist: (NSString *) optlist;
- (NSInteger) begin_item: (NSString *) tagname optlist: (NSString *) optlist;
- (void) begin_layer: (NSInteger) layer;
- (void) begin_mc: (NSString *) tagname optlist: (NSString *) optlist;
- (void) begin_page: (double) width height: (double) height;
- (void) begin_page_ext: (double) width height: (double) height optlist: (NSString *) optlist;
- (NSInteger) begin_pattern: (double) width height: (double) height xstep: (double) xstep ystep: (double) ystep painttype: (NSInteger) painttype;
- (NSInteger) begin_pattern_ext: (double) width height: (double) height optlist: (NSString *) optlist;
- (NSInteger) begin_template: (double) width height: (double) height;
- (NSInteger) begin_template_ext: (double) width height: (double) height optlist: (NSString *) optlist;
- (void) circle: (double) x y: (double) y r: (double) r;
- (void) circular_arc: (double) x1 y1: (double) y1 x2: (double) x2 y2: (double) y2;
- (void) clip;
- (void) close;
- (void) close_font: (NSInteger) font;
- (void) close_graphics: (NSInteger) graphics;
- (void) close_image: (NSInteger) image;
- (void) close_pdi: (NSInteger) doc;
- (void) close_pdi_document: (NSInteger) doc;
- (void) close_pdi_page: (NSInteger) page;
- (void) closepath;
- (void) closepath_fill_stroke;
- (void) closepath_stroke;
- (void) concat: (double) a b: (double) b c: (double) c d: (double) d e: (double) e f: (double) f;
- (void) continue_text: (NSString *) text;
- (NSData *) convert_to_unicode: (NSString *) inputformat inputstring: (NSData *) inputstring optlist: (NSString *) optlist;
- (NSInteger) create_3dview: (NSString *) username optlist: (NSString *) optlist;
- (NSInteger) create_action: (NSString *) type optlist: (NSString *) optlist;
- (void) create_annotation: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury type: (NSString *) type optlist: (NSString *) optlist;
- (NSInteger) create_devicen: (NSString *) optlist;
- (NSInteger) create_bookmark: (NSString *) text optlist: (NSString *) optlist;
- (void) create_field: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury name: (NSString *) name type: (NSString *) type optlist: (NSString *) optlist;
- (void) create_fieldgroup: (NSString *) name optlist: (NSString *) optlist;
- (NSInteger) create_gstate: (NSString *) optlist;
- (void) create_pvf: (NSString *) filename data: (NSData *) data optlist: (NSString *) optlist;
- (NSInteger) create_textflow: (NSString *) text optlist: (NSString *) optlist;
- (void) curveto: (double) x1 y1: (double) y1 x2: (double) x2 y2: (double) y2 x3: (double) x3 y3: (double) y3;
- (NSInteger) define_layer: (NSString *) name optlist: (NSString *) optlist;
- (void) delete_path: (NSInteger) path;
- (NSInteger) delete_pvf: (NSString *) filename;
- (void) delete_table: (NSInteger) table optlist: (NSString *) optlist;
- (void) delete_textflow: (NSInteger) textflow;
- (void) draw_path: (NSInteger) path x: (double) x y: (double) y optlist: (NSString *) optlist;
- (void) ellipse: (double) x y: (double) y rx: (double) rx ry: (double) ry;
- (void) elliptical_arc: (double) x y: (double) y rx: (double) rx ry: (double) ry optlist: (NSString *) optlist;
- (void) encoding_set_char: (NSString *) encoding slot: (NSInteger) slot glyphname: (NSString *) glyphname uv: (NSInteger) uv;
- (void) end_document: (NSString *) optlist;
- (void) end_dpart: (NSString *) optlist;
- (void) end_font;
- (void) end_glyph;
- (void) end_item: (NSInteger) id;
- (void) end_layer;
- (void) end_mc;
- (void) end_page;
- (void) end_page_ext: (NSString *) optlist;
- (void) end_pattern;
- (void) end_template;
- (void) end_template_ext: (double) width height: (double) height;
- (void) endpath;
- (void) fill;
- (NSInteger) fill_graphicsblock: (NSInteger) page blockname: (NSString *) blockname graphics: (NSInteger) graphics optlist: (NSString *) optlist;
- (NSInteger) fill_imageblock: (NSInteger) page blockname: (NSString *) blockname image: (NSInteger) image optlist: (NSString *) optlist;
- (NSInteger) fill_pdfblock: (NSInteger) page blockname: (NSString *) blockname contents: (NSInteger) contents optlist: (NSString *) optlist;
- (void) fill_stroke;
- (NSInteger) fill_textblock: (NSInteger) page blockname: (NSString *) blockname text: (NSString *) text optlist: (NSString *) optlist;
- (NSInteger) findfont: (NSString *) fontname encoding: (NSString *) encoding embed: (NSInteger) embed;
- (void) fit_graphics: (NSInteger) graphics x: (double) x y: (double) y optlist: (NSString *) optlist;
- (void) fit_image: (NSInteger) image x: (double) x y: (double) y optlist: (NSString *) optlist;
- (void) fit_pdi_page: (NSInteger) page x: (double) x y: (double) y optlist: (NSString *) optlist;
- (NSString *) fit_table: (NSInteger) table llx: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury optlist: (NSString *) optlist;
- (NSString *) fit_textflow: (NSInteger) textflow llx: (double) llx lly: (double) lly urx: (double) urx ury: (double) ury optlist: (NSString *) optlist;
- (void) fit_textline: (NSString *) text x: (double) x y: (double) y optlist: (NSString *) optlist;
- (NSString *) get_apiname;
- (NSData *) get_buffer;
- (NSString *) get_errmsg;
- (NSInteger) get_errnum;
- (double) get_option: (NSString *) keyword optlist: (NSString *) optlist;
- (NSString *) get_parameter: (NSString *) key modifier: (double) modifier;
- (double) get_pdi_value: (NSString *) key doc: (NSInteger) doc page: (NSInteger) page reserved: (NSInteger) reserved;
- (NSString *) get_string: (NSInteger) idx optlist: (NSString *) optlist;
- (double) get_value: (NSString *) key modifier: (double) modifier;
- (double) info_font: (NSInteger) font keyword: (NSString *) keyword optlist: (NSString *) optlist;
- (double) info_graphics: (NSInteger) graphics keyword: (NSString *) keyword optlist: (NSString *) optlist;
- (double) info_image: (NSInteger) image keyword: (NSString *) keyword optlist: (NSString *) optlist;
- (double) info_matchbox: (NSString *) boxname num: (NSInteger) num keyword: (NSString *) keyword;
- (double) info_path: (NSInteger) path keyword: (NSString *) keyword optlist: (NSString *) optlist;
- (double) info_pdi_page: (NSInteger) page keyword: (NSString *) keyword optlist: (NSString *) optlist;
- (double) info_pvf: (NSString *) filename keyword: (NSString *) keyword;
- (double) info_table: (NSInteger) table keyword: (NSString *) keyword;
- (double) info_textflow: (NSInteger) textflow keyword: (NSString *) keyword;
- (double) info_textline: (NSString *) text keyword: (NSString *) keyword optlist: (NSString *) optlist;
- (void) initgraphics;
- (void) lineto: (double) x y: (double) y;
- (NSInteger) load_3ddata: (NSString *) filename optlist: (NSString *) optlist;
- (NSInteger) load_asset: (NSString *) type filename: (NSString *) filename optlist: (NSString *) optlist;
- (NSInteger) load_font: (NSString *) fontname encoding: (NSString *) encoding optlist: (NSString *) optlist;
- (NSInteger) load_graphics: (NSString *) type filename: (NSString *) filename optlist: (NSString *) optlist;
- (NSInteger) load_iccprofile: (NSString *) profilename optlist: (NSString *) optlist;
- (NSInteger) load_image: (NSString *) imagetype filename: (NSString *) filename optlist: (NSString *) optlist;
- (NSInteger) makespotcolor: (NSString *) spotname;
- (void) mc_point: (NSString *) tagname optlist: (NSString *) optlist;
- (void) moveto: (double) x y: (double) y;
- (NSInteger) open_CCITT: (NSString *) filename width: (NSInteger) width height: (NSInteger) height BitReverse: (NSInteger) BitReverse K: (NSInteger) K BlackIs1: (NSInteger) BlackIs1;
- (NSInteger) open_file: (NSString *) filename;
- (NSInteger) open_image_file: (NSString *) imagetype filename: (NSString *) filename stringparam: (NSString *) stringparam intparam: (NSInteger) intparam;
- (NSInteger) open_pdi_document: (NSString *) filename optlist: (NSString *) optlist;
- (NSInteger) open_pdi_page: (NSInteger) doc pagenumber: (NSInteger) pagenumber optlist: (NSString *) optlist;
- (double) pcos_get_number: (NSInteger) doc path: (NSString *) path;
- (NSString *) pcos_get_string: (NSInteger) doc path: (NSString *) path;
- (NSData *) pcos_get_stream: (NSInteger) doc optlist: (NSString *) optlist path: (NSString *) path;
- (void) place_image: (NSInteger) image x: (double) x y: (double) y scale: (double) scale;
- (void) place_pdi_page: (NSInteger) page x: (double) x y: (double) y sx: (double) sx sy: (double) sy;
- (void) poca_delete: (NSInteger) container optlist: (NSString *) optlist;
- (void) poca_insert: (NSInteger) container optlist: (NSString *) optlist;
- (NSInteger) poca_new: (NSString *) optlist;
- (void) poca_remove: (NSInteger) container optlist: (NSString *) optlist;
- (NSInteger) process_pdi: (NSInteger) doc page: (NSInteger) page optlist: (NSString *) optlist;
- (void) rect: (double) x y: (double) y width: (double) width height: (double) height;
- (void) restore;
- (void) resume_page: (NSString *) optlist;
- (void) rotate: (double) phi;
- (void) save;
- (void) scale: (double) sx sy: (double) sy;
- (void) set_border_color: (double) red green: (double) green blue: (double) blue;
- (void) set_border_dash: (double) b w: (double) w;
- (void) set_border_style: (NSString *) style width: (double) width;
- (void) set_graphics_option: (NSString *) optlist;
- (void) set_gstate: (NSInteger) gstate;
- (void) set_info: (NSString *) key value: (NSString *) value;
- (void) set_layer_dependency: (NSString *) type optlist: (NSString *) optlist;
- (void) set_option: (NSString *) optlist;
- (void) set_parameter: (NSString *) key value: (NSString *) value;
- (void) set_text_option: (NSString *) optlist;
- (void) set_text_pos: (double) x y: (double) y;
- (void) set_value: (NSString *) key value: (double) value;
- (void) setcolor: (NSString *) fstype colorspace: (NSString *) colorspace c1: (double) c1 c2: (double) c2 c3: (double) c3 c4: (double) c4;
- (void) setdash: (double) b w: (double) w;
- (void) setdashpattern: (NSString *) optlist;
- (void) setflat: (double) flatness;
- (void) setfont: (NSInteger) font fontsize: (double) fontsize;
- (void) setgray: (double) gray;
- (void) setgray_fill: (double) gray;
- (void) setgray_stroke: (double) gray;
- (void) setlinecap: (NSInteger) linecap;
- (void) setlinejoin: (NSInteger) linejoin;
- (void) setlinewidth: (double) width;
- (void) setmatrix: (double) a b: (double) b c: (double) c d: (double) d e: (double) e f: (double) f;
- (void) setmiterlimit: (double) miter;
- (void) setrgbcolor: (double) red green: (double) green blue: (double) blue;
- (void) setrgbcolor_fill: (double) red green: (double) green blue: (double) blue;
- (void) setrgbcolor_stroke: (double) red green: (double) green blue: (double) blue;
- (NSInteger) shading: (NSString *) type x0: (double) x0 y0: (double) y0 x1: (double) x1 y1: (double) y1 c1: (double) c1 c2: (double) c2 c3: (double) c3 c4: (double) c4 optlist: (NSString *) optlist;
- (NSInteger) shading_pattern: (NSInteger) shading optlist: (NSString *) optlist;
- (void) shfill: (NSInteger) shading;
- (void) show: (NSString *) text;
- (void) show_xy: (NSString *) text x: (double) x y: (double) y;
- (void) skew: (double) alpha beta: (double) beta;
- (double) stringwidth: (NSString *) text font: (NSInteger) font fontsize: (double) fontsize;
- (void) stroke;
- (void) suspend_page: (NSString *) optlist;
- (void) translate: (double) tx ty: (double) ty;
@end
