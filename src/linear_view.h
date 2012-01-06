// Thomas Nagy 2007-2012 GPLV3

#ifndef LINEAR_VIEW_H
#define LINEAR_VIEW_H

#include <QTreeWidget>
#include <QMap>

class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;
class QMouseEvent;
class QMimeData;

class linear_view : public QTreeWidget
{
	Q_OBJECT
	public:
		linear_view(QWidget *i_oParent, sem_model *i_oControl);
		sem_model *m_oControl;

		QMap<int, QTreeWidgetItem*> m_oItems;

		bool filter_item(QTreeWidgetItem * i_oItem, const QString & i_oS);

		void dropEvent(QDropEvent *);

		bool m_bLockSelect;

	public slots:
		void filter_slot(const QString & i_oS);
		void selection_changed();

		void notify_add_item(int id);
		void notify_repaint(int id);
		void notify_delete_item(int id);
		void notify_link_items(int id1, int id2);
		void notify_unlink_items(int id1, int id2);
		void notify_select(const QList<int>& unsel, const QList<int>& sel);
		void notify_sort(int id);
		void notify_edit(int id);
};

#endif

