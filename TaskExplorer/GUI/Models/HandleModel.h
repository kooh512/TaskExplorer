#pragma once
#include <qwidget.h>
#include "Common/ListItemModel.h"
#include "..\..\API\HandleInfo.h"

class CHandleModel : public CListItemModel
{
    Q_OBJECT

public:
    CHandleModel(QObject *parent = 0);
	~CHandleModel();

	void			Sync(QMap<quint64, CHandlePtr> HandleList);

	CHandlePtr		GetHandle(const QModelIndex &index) const;

	int				columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant		headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	enum EColumns
	{
		eProcess = 0,
		eHandle,
		eType, // including sub type
		eName,
		ePosition,
		eSize,
		eGrantedAccess,
#ifdef WIN32
		eFileShareAccess,
		eAttributes,
		eObjectAddress,
		eOriginalName,
#endif
		eCount
	};

protected:
	struct SHandleNode: SListNode
	{
		SHandleNode(const QVariant& Id) : SListNode(Id) {}

		CHandlePtr			pHandle;
	};

	virtual SListNode* MkNode(const QVariant& Id) { return new SHandleNode(Id); }

	
	virtual QVariant GetDefaultIcon() const;
};