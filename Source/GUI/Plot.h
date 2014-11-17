/*  Copyright (c) BAVC. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license that can
 *  be found in the License.html file in the root of the source tree.
 */

//---------------------------------------------------------------------------
#ifndef GUI_Plot_H
#define GUI_Plot_H
//---------------------------------------------------------------------------

#include <Core/Core.h>
#include <qwt_plot.h>

class QwtPlotCurve;
class PlotCursor;

//***************************************************************************
// Class
//***************************************************************************

class Plot : public QwtPlot
{
    Q_OBJECT

public:
    explicit Plot( PlotType Type, QWidget *parent );
    virtual ~Plot();

    void setCursorPos( double x );

    void setCurveSamples( int index,
        const double *xData, const double *yData, int size );

Q_SIGNALS:
    void cursorMoved( double x );

private Q_SLOTS:
    void onPickerMoved( const QPointF& );
    void onXScaleChanged();

private:
    QColor curveColor( int index ) const;

    const PlotType          m_type;
    QVector<QwtPlotCurve*>  m_curves;
    PlotCursor*             m_cursor;
};

#endif // GUI_Plot_H