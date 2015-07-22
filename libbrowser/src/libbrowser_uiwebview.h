/* Copyright (C) 2003-2015 Runtime Revolution Ltd.
 
 This file is part of LiveCode.
 
 LiveCode is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License v3 as published by the Free
 Software Foundation.
 
 LiveCode is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.
 
 You should have received a copy of the GNU General Public License
 along with LiveCode.  If not see <http://www.gnu.org/licenses/>.  */

#ifndef __LIBBROWSER_IOS_H__
#define __LIBBROWSER_IOS_H__

#include "libbrowser_internal.h"

@class MCUIWebViewBrowserDelegate;

class MCUIWebViewBrowser : public MCBrowserBase
{
public:
	MCUIWebViewBrowser();
	virtual ~MCUIWebViewBrowser();
	
	bool Init(void);
	
	virtual void *GetNativeLayer();
	
	virtual bool GetRect(MCBrowserRect &r_rect);
	virtual bool SetRect(const MCBrowserRect &p_rect);
	
	virtual bool GetBoolProperty(MCBrowserProperty p_property, bool &r_value);
	virtual bool SetBoolProperty(MCBrowserProperty p_property, bool p_value);
	
	virtual bool GetStringProperty(MCBrowserProperty p_property, char *&r_utf8_string);
	virtual bool SetStringProperty(MCBrowserProperty p_property, const char *p_utf8_string);
	
	virtual bool GoBack();
	virtual bool GoForward();
	virtual bool GoToURL(const char *p_url);
	virtual bool EvaluateJavaScript(const char *p_script, char *&r_result);

protected:
	bool GetUrl(char *& r_url);
	
	bool GetHTMLText(char *&r_htmltext);
	bool SetHTMLText(const char *p_htmltext);
	
	bool GetScrollingEnabled(bool& r_value);
	bool SetScrollingEnabled(bool p_value);
	
	// Browser-specific actions
	bool ExecAdvance();
	bool ExecRetreat();
	bool ExecReload();
	bool ExecStop();
	bool ExecExecute(const char * p_script);
	bool ExecLoad(const char *p_url, const char *p_html);
	
	UIScrollView *GetScrollView(void);
	
private:
	bool GetView(UIWebView *&r_view);
	
	UIWebView *m_view;
	MCUIWebViewBrowserDelegate *m_delegate;
};

//////////

bool MCUIWebViewBrowserFactoryCreate(MCBrowserFactoryRef &r_factory);

#endif // __LIBBROWSER_IOS_H__
